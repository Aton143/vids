#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "raylib.h"
#include "raymath.h"

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

typedef uintptr_t ptr_val;

typedef float    f32;
typedef double   f64;

typedef i8       b8;
typedef i32      b32;
typedef i64      b64;

#define array_count(a) ((sizeof(a))/(sizeof(*a)))

#define GLSL_VERSION 330

static float randf(float min, float max)
{
  float random_float = ((float) rand()) / ((float) RAND_MAX);
  return Lerp(min, max, random_float);
}

typedef void           *LPVOID;
typedef const void     *LPCVOID;
typedef void           *HANDLE;
typedef HANDLE         *PHANDLE;
typedef unsigned long   DWORD;
typedef DWORD          *LPDWORD;
typedef int             BOOL;
typedef char            CHAR;
typedef CHAR           *LPSTR;
typedef const CHAR     *LPCSTR;
typedef unsigned short  WORD;
typedef unsigned char   BYTE;
typedef BYTE           *LPBYTE;

typedef struct _SECURITY_ATTRIBUTES {
  DWORD nLength;
  LPVOID lpSecurityDescriptor;
  BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _STARTUPINFOA {
  DWORD  cb;
  LPSTR  lpReserved;
  LPSTR  lpDesktop;
  LPSTR  lpTitle;
  DWORD  dwX;
  DWORD  dwY;
  DWORD  dwXSize;
  DWORD  dwYSize;
  DWORD  dwXCountChars;
  DWORD  dwYCountChars;
  DWORD  dwFillAttribute;
  DWORD  dwFlags;
  WORD   wShowWindow;
  WORD   cbReserved2;
  LPBYTE lpReserved2;
  HANDLE hStdInput;
  HANDLE hStdOutput;
  HANDLE hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;

typedef struct _PROCESS_INFORMATION {
  HANDLE hProcess;
  HANDLE hThread;
  DWORD  dwProcessId;
  DWORD  dwThreadId;
} PROCESS_INFORMATION, *LPPROCESS_INFORMATION;

#define ZeroMemory(destination, length) memset(destination, 0, length)

#define TRUE 1
#define HANDLE_FLAG_INHERIT 0x1
#define STD_INPUT_HANDLE ((DWORD)-10)
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#define STD_ERROR_HANDLE ((DWORD)-12)
#define STARTF_USESTDHANDLES 0x00000100
#define INFINITE ((DWORD) -1)
#define WAIT_FAILED ((DWORD) 0xFFFFFFFF)

struct FFMPEG {
  HANDLE hProcess;
  HANDLE hPipeWrite;
};

typedef BOOL CreatePipe_Function(PHANDLE hReadPipe, PHANDLE hWritePipe, LPSECURITY_ATTRIBUTES lpPipeAttributes, DWORD nSize);
typedef BOOL SetHandleInformation_Function(HANDLE hObject, DWORD dwMask, DWORD dwFlags);
typedef HANDLE GetStdHandle_Function(DWORD nStdHandle);
typedef BOOL CreateProcessA_Function(LPCSTR                lpApplicationName,
                                     LPSTR                 lpCommandLine,
                                     LPSECURITY_ATTRIBUTES lpProcessAttributes,
                                     LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                     BOOL                  bInheritHandles,
                                     DWORD                 dwCreationFlags,
                                     LPVOID                lpEnvironment,
                                     LPCSTR                lpCurrentDirectory,
                                     LPSTARTUPINFOA        lpStartupInfo,
                                     LPPROCESS_INFORMATION lpProcessInformation);
typedef BOOL CloseHandle_Function(HANDLE hObject);
typedef BOOL WriteFile_Function(HANDLE       hFile,
                                LPCVOID      lpBuffer,
                                DWORD        nNumberOfBytesToWrite,
                                LPDWORD      lpNumberOfBytesWritten,
                                // NOTE(antoniom): actually LPOVERLAPPED
                                LPVOID       lpOverlapped);
typedef BOOL FlushFileBuffers_Function(HANDLE hFile);
typedef DWORD WaitForSingleObject_Function(HANDLE hHandle, DWORD dwMilliseconds);
typedef BOOL GetExitCodeProcess_Function(HANDLE  hProcess, LPDWORD lpExitCode);

extern "C" CreatePipe_Function CreatePipe;
extern "C" SetHandleInformation_Function SetHandleInformation;
extern "C" GetStdHandle_Function GetStdHandle;
extern "C" CreateProcessA_Function CreateProcessA;
extern "C" CloseHandle_Function CloseHandle;
extern "C" WriteFile_Function WriteFile;
extern "C" FlushFileBuffers_Function FlushFileBuffers;
extern "C" WaitForSingleObject_Function WaitForSingleObject;
extern "C" GetExitCodeProcess_Function GetExitCodeProcess;

static FFMPEG *ffmpeg_start_rendering(size_t width, size_t height, size_t fps)
{
    HANDLE pipe_read;
    HANDLE pipe_write;

    SECURITY_ATTRIBUTES saAttr = {0};
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;

    if (!CreatePipe(&pipe_read, &pipe_write, &saAttr, 0)) {
        // fprintf(stderr, "ERROR: Could not create pipe: %s\n", GetLastErrorAsString());
        return NULL;
    }

    if (!SetHandleInformation(pipe_write, HANDLE_FLAG_INHERIT, 0)) {
        // fprintf(stderr, "ERROR: Could not SetHandleInformation: %s\n", GetLastErrorAsString());
        return NULL;
    }

    // https://docs.microsoft.com/en-us/windows/win32/procthread/creating-a-child-process-with-redirected-input-and-output

    STARTUPINFOA siStartInfo;
    ZeroMemory(&siStartInfo, sizeof(siStartInfo));
    siStartInfo.cb = sizeof(siStartInfo);
    // NOTE: theoretically setting NULL to std handles should not be a problem
    // https://docs.microsoft.com/en-us/windows/console/getstdhandle?redirectedfrom=MSDN#attachdetach-behavior
    siStartInfo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    // TODO(#32): check for errors in GetStdHandle
    siStartInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    siStartInfo.hStdInput = pipe_read;
    siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

    PROCESS_INFORMATION piProcInfo;
    ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));

    char cmd_buffer[1024*2];
    snprintf(cmd_buffer, sizeof(cmd_buffer), "ffmpeg.exe -loglevel verbose -y -f rawvideo -pix_fmt rgba -s %zdx%zd -r %zd -i - -c:v libx264 -vb 2500k -c:a aac -ab 200k -pix_fmt yuv420p output.mp4", width, height, fps);

    BOOL bSuccess =
        CreateProcessA(
            NULL,
            cmd_buffer,
            NULL,
            NULL,
            TRUE,
            0,
            NULL,
            NULL,
            &siStartInfo,
            &piProcInfo
        );

    if (!bSuccess) {
        // fprintf(stderr, "ERROR: Could not create child process: %s\n", GetLastErrorAsString());
        return NULL;
    }

    CloseHandle(pipe_read);
    CloseHandle(piProcInfo.hThread);

    // TODO: use Windows specific allocation stuff?
    FFMPEG *ffmpeg = (FFMPEG *) malloc(sizeof(FFMPEG));
    assert(ffmpeg != NULL && "Buy MORE RAM lol!!");
    ffmpeg->hProcess = piProcInfo.hProcess;
    // ffmpeg->hPipeRead = pipe_read;
    ffmpeg->hPipeWrite = pipe_write;
    return ffmpeg;
}

static void ffmpeg_send_frame(FFMPEG *ffmpeg, void *data, size_t width, size_t height)
{
    WriteFile(ffmpeg->hPipeWrite, data, sizeof(uint32_t)*width*height, NULL, NULL);
}

static void ffmpeg_send_frame_flipped(FFMPEG *ffmpeg, void *data, size_t width, size_t height)
{
    for (size_t y = height; y > 0; --y) {
        WriteFile(ffmpeg->hPipeWrite, (uint32_t*)data + (y - 1)*width, sizeof(uint32_t)*width, NULL, NULL);
    }
}

#if 1
void ffmpeg_end_rendering(FFMPEG *ffmpeg)
{
    FlushFileBuffers(ffmpeg->hPipeWrite);
    // FlushFileBuffers(ffmpeg->hPipeRead);

    CloseHandle(ffmpeg->hPipeWrite);
    // CloseHandle(ffmpeg->hPipeRead);

    DWORD result = WaitForSingleObject(
                       ffmpeg->hProcess,     // HANDLE hHandle,
                       INFINITE // DWORD  dwMilliseconds
                   );

    if (result == WAIT_FAILED) {
        // fprintf(stderr, "ERROR: could not wait on child process: %s\n", GetLastErrorAsString());
        return;
    }

    DWORD exit_status;
    if (GetExitCodeProcess(ffmpeg->hProcess, &exit_status) == 0) {
        // fprintf(stderr, "ERROR: could not get process exit code: %lu\n", GetLastError());
        return;
    }

    if (exit_status != 0) {
        fprintf(stderr, "ERROR: command exited with exit code %lu\n", exit_status);
        return;
    }

    CloseHandle(ffmpeg->hProcess);
}
#endif

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screen_width = 800;
  const int screen_height = 450;

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(screen_width, screen_height, "Vids");

  SetTargetFPS(30);

  FFMPEG *ffmpeg = ffmpeg_start_rendering(screen_width, screen_height, 30);

  // Define the camera to look into our 3d world
  Camera camera = {0};
  camera.position = {2.0f, 4.0f, 6.0f};    // Camera position
  camera.target = {0.0f, 0.5f, 0.0f};      // Camera looking at point
  camera.up = {0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;                               // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE;            // Camera projection type

  Vector3 triangle_pos[26][3] = {0};
  Vector3 triangle_vel[26] = {0};

  for (u32 triangle_index = 0; triangle_index < array_count(triangle_pos); triangle_index += 1)
  {
    triangle_pos[triangle_index][0] = {randf(0.0f, 1.0f), randf(0.0f, 1.0f), randf(0.0f, 1.0f)};
    triangle_pos[triangle_index][1] = {randf(0.0f, 1.0f), randf(0.0f, 1.0f), randf(0.0f, 1.0f)};
    triangle_pos[triangle_index][2] = {randf(0.0f, 1.0f), randf(0.0f, 1.0f), randf(0.0f, 1.0f)};
    triangle_vel[triangle_index] = {randf(0.0f, 1.0f), randf(0.0f, 1.0f), randf(0.0f, 1.0f)};

  }

  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    f32 delta = GetFrameTime();
    for (u32 triangle_index = 0; triangle_index < array_count(triangle_pos); triangle_index += 1)
    {
      Vector3 velocity_vector = Vector3Scale(triangle_vel[triangle_index], delta);
      triangle_pos[triangle_index][0] = Vector3Add(triangle_pos[triangle_index][0], velocity_vector);
      triangle_pos[triangle_index][1] = Vector3Add(triangle_pos[triangle_index][1], velocity_vector);
      triangle_pos[triangle_index][2] = Vector3Add(triangle_pos[triangle_index][2], velocity_vector);
    }

    UpdateCamera(&camera, CAMERA_FREE);

    BeginDrawing();
    {
      ClearBackground(RAYWHITE);
      BeginMode3D(camera);
      {
        for (u32 triangle_index = 0; triangle_index < array_count(triangle_pos); triangle_index += 1)
        {
          DrawTriangle3D(triangle_pos[triangle_index][0],
                         triangle_pos[triangle_index][1],
                         triangle_pos[triangle_index][2],
                         LIGHTGRAY);
        }
      }
      EndMode3D();
    }

    DrawFPS(10, 10);
    DrawText(TextFormat("- Position: (%06.3f, %06.3f, %06.3f)",
                        camera.position.x, camera.position.y, camera.position.z), 610, 60, 10, BLACK);
    DrawText(TextFormat("- Target: (%06.3f, %06.3f, %06.3f)",
                        camera.target.x, camera.target.y, camera.target.z), 610, 75, 10, BLACK);
    DrawText(TextFormat("- Up: (%06.3f, %06.3f, %06.3f)",
                        camera.up.x, camera.up.y, camera.up.z), 610, 90, 10, BLACK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
