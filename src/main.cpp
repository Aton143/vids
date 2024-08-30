#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include <tchar.h>
#include <evr.h>
#include <mfapi.h>
#include <mfplay.h>
#include <mfreadwrite.h>
#include <mferror.h>
#include <wmcodecdsp.h>

#include <string>
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

#define array_count(arr) (sizeof(arr) / sizeof((arr)[0]))

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "mediafoundation.h"

typedef struct _stat64 stat64;

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**) 
{
  HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

  if (SUCCEEDED(hr))
  {
    hr = MFStartup(MF_VERSION);
  }

  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
  {
    return(1);
  }

  const char* glsl_version = "#version 130";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create window with graphics context
  GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
  if (window == NULL)
  {
    return(1);
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

  // Setup Dear ImGui style
  ImGui::StyleColorsDark();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  // Our state
  bool   show_demo_window = true;
  ImVec4 clear_color      = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  struct texture
  {
    GLuint id;
    s32    width;
    s32    height;
  };

  texture textures[98] = {0};

  for (s32 texture_idx = 0; texture_idx < array_count(textures); texture_idx += 1)
  {
    texture *cur_texture = &textures[texture_idx];

    u8 file_name[256] = {};
    sprintf_s((char *) file_name, sizeof(file_name), "big_buck_bunny_%04d.png", texture_idx + 1);

    s32      png_fd       = -1;
    stat64   file_stat    = {};
    errno_t  libc_err     = _sopen_s(&png_fd, (char *) file_name, _O_RDONLY | _O_BINARY, _SH_DENYNO, _S_IREAD);
    u64      png_file_size = 0;
    u8      *png_file_data = NULL;
    s32      png_file_read = 0;

    if (libc_err == 0)
    {
      if (_fstat64(png_fd, &file_stat) == 0)
      {
        png_file_size = (u64) file_stat.st_size;
        png_file_data = (u8 *) calloc(png_file_size, 1);
        png_file_read = _read(png_fd, png_file_data, (s32) png_file_size);
      }
    }

    if (png_file_read == (s32) png_file_size)
    {
      u8 *image_data = stbi_load_from_memory(png_file_data,
                                             png_file_size,
                                             &cur_texture->width,
                                             &cur_texture->height,
                                             NULL,
                                             4);

      if (image_data != 0)
      {
        // Create a OpenGL texture identifier
        glGenTextures(1, &cur_texture->id);
        glBindTexture(GL_TEXTURE_2D, cur_texture->id);

        // Setup filtering parameters for display
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Upload pixels into texture
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     GL_RGBA,
                     cur_texture->width,
                     cur_texture->height,
                     0,
                     GL_RGBA,
                     GL_UNSIGNED_BYTE,
                     image_data);

        stbi_image_free(image_data);
      }
      else
      {
        int *zero = 0;
        *zero = 0;
      }
    }

    _close(png_fd);
    free(png_file_data);
  }

  s32 frame_num = 0;
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    if (glfwGetWindowAttrib(window, GLFW_ICONIFIED))
    {
      ImGui_ImplGlfw_Sleep(10);
      continue;
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    texture *cur_texture = &textures[frame_num];

    ImGui::Begin("OpenGL Texture Text");
    ImGui::Text("pointer = %x", cur_texture->id);
    ImGui::Text("size = %d x %d", cur_texture->width, cur_texture->height);
    ImGui::Image((void*)(intptr_t) cur_texture->id, ImVec2(cur_texture->width, cur_texture->height));
    ImGui::End();

    // Rendering
    ImGui::Render();
    int display_w = 0, display_h = 0;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);

    frame_num += 1;
    if (frame_num >= array_count(textures))
    {
      frame_num = 0;
    }
  }

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return(0);
}
