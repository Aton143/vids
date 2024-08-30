#pragma once

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "mf.lib")
#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mfplay.lib")
#pragma comment(lib, "mfreadwrite.lib")
#pragma comment(lib, "mfuuid.lib")
#pragma comment(lib, "wmcodecdspuuid.lib")

#define IF_EQUAL_RETURN(param, val) if(val == param) return #val
char *get_guid_name_const(GUID guid)
{
  IF_EQUAL_RETURN(guid, MF_MT_MAJOR_TYPE);
  IF_EQUAL_RETURN(guid, MF_MT_MAJOR_TYPE);
  IF_EQUAL_RETURN(guid, MF_MT_SUBTYPE);
  IF_EQUAL_RETURN(guid, MF_MT_ALL_SAMPLES_INDEPENDENT);
  IF_EQUAL_RETURN(guid, MF_MT_FIXED_SIZE_SAMPLES);
  IF_EQUAL_RETURN(guid, MF_MT_COMPRESSED);
  IF_EQUAL_RETURN(guid, MF_MT_SAMPLE_SIZE);
  IF_EQUAL_RETURN(guid, MF_MT_WRAPPED_TYPE);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_NUM_CHANNELS);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_SAMPLES_PER_SECOND);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_FLOAT_SAMPLES_PER_SECOND);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_AVG_BYTES_PER_SECOND);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_BLOCK_ALIGNMENT);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_BITS_PER_SAMPLE);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_VALID_BITS_PER_SAMPLE);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_SAMPLES_PER_BLOCK);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_CHANNEL_MASK);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_FOLDDOWN_MATRIX);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_PEAKREF);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_PEAKTARGET);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_AVGREF);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_WMADRC_AVGTARGET);
  IF_EQUAL_RETURN(guid, MF_MT_AUDIO_PREFER_WAVEFORMATEX);
  IF_EQUAL_RETURN(guid, MF_MT_AAC_PAYLOAD_TYPE);
  IF_EQUAL_RETURN(guid, MF_MT_AAC_AUDIO_PROFILE_LEVEL_INDICATION);
  IF_EQUAL_RETURN(guid, MF_MT_FRAME_SIZE);
  IF_EQUAL_RETURN(guid, MF_MT_FRAME_RATE);
  IF_EQUAL_RETURN(guid, MF_MT_FRAME_RATE_RANGE_MAX);
  IF_EQUAL_RETURN(guid, MF_MT_FRAME_RATE_RANGE_MIN);
  IF_EQUAL_RETURN(guid, MF_MT_PIXEL_ASPECT_RATIO);
  IF_EQUAL_RETURN(guid, MF_MT_DRM_FLAGS);
  IF_EQUAL_RETURN(guid, MF_MT_PAD_CONTROL_FLAGS);
  IF_EQUAL_RETURN(guid, MF_MT_SOURCE_CONTENT_HINT);
  IF_EQUAL_RETURN(guid, MF_MT_VIDEO_CHROMA_SITING);
  IF_EQUAL_RETURN(guid, MF_MT_INTERLACE_MODE);
  IF_EQUAL_RETURN(guid, MF_MT_TRANSFER_FUNCTION);
  IF_EQUAL_RETURN(guid, MF_MT_VIDEO_PRIMARIES);
  IF_EQUAL_RETURN(guid, MF_MT_CUSTOM_VIDEO_PRIMARIES);
  IF_EQUAL_RETURN(guid, MF_MT_YUV_MATRIX);
  IF_EQUAL_RETURN(guid, MF_MT_VIDEO_LIGHTING);
  IF_EQUAL_RETURN(guid, MF_MT_VIDEO_NOMINAL_RANGE);
  IF_EQUAL_RETURN(guid, MF_MT_GEOMETRIC_APERTURE);
  IF_EQUAL_RETURN(guid, MF_MT_MINIMUM_DISPLAY_APERTURE);
  IF_EQUAL_RETURN(guid, MF_MT_PAN_SCAN_APERTURE);
  IF_EQUAL_RETURN(guid, MF_MT_PAN_SCAN_ENABLED);
  IF_EQUAL_RETURN(guid, MF_MT_AVG_BITRATE);
  IF_EQUAL_RETURN(guid, MF_MT_AVG_BIT_ERROR_RATE);
  IF_EQUAL_RETURN(guid, MF_MT_MAX_KEYFRAME_SPACING);
  IF_EQUAL_RETURN(guid, MF_MT_DEFAULT_STRIDE);
  IF_EQUAL_RETURN(guid, MF_MT_PALETTE);
  IF_EQUAL_RETURN(guid, MF_MT_USER_DATA);
  IF_EQUAL_RETURN(guid, MF_MT_AM_FORMAT_TYPE);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG_START_TIME_CODE);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG2_PROFILE);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG2_LEVEL);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG2_FLAGS);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG_SEQUENCE_HEADER);
  IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_SRC_PACK_0);
  IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_CTRL_PACK_0);
  IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_SRC_PACK_1);
  IF_EQUAL_RETURN(guid, MF_MT_DV_AAUX_CTRL_PACK_1);
  IF_EQUAL_RETURN(guid, MF_MT_DV_VAUX_SRC_PACK);
  IF_EQUAL_RETURN(guid, MF_MT_DV_VAUX_CTRL_PACK);
  IF_EQUAL_RETURN(guid, MF_MT_ARBITRARY_HEADER);
  IF_EQUAL_RETURN(guid, MF_MT_ARBITRARY_FORMAT);
  IF_EQUAL_RETURN(guid, MF_MT_IMAGE_LOSS_TOLERANT);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG4_SAMPLE_DESCRIPTION);
  IF_EQUAL_RETURN(guid, MF_MT_MPEG4_CURRENT_SAMPLE_ENTRY);
  IF_EQUAL_RETURN(guid, MF_MT_ORIGINAL_4CC);
  IF_EQUAL_RETURN(guid, MF_MT_ORIGINAL_WAVE_FORMAT_TAG);

  IF_EQUAL_RETURN(guid, MFMediaType_Audio);
  IF_EQUAL_RETURN(guid, MFMediaType_Video);
  IF_EQUAL_RETURN(guid, MFMediaType_Protected);
  IF_EQUAL_RETURN(guid, MFMediaType_SAMI);
  IF_EQUAL_RETURN(guid, MFMediaType_Script);
  IF_EQUAL_RETURN(guid, MFMediaType_Image);
  IF_EQUAL_RETURN(guid, MFMediaType_HTML);
  IF_EQUAL_RETURN(guid, MFMediaType_Binary);
  IF_EQUAL_RETURN(guid, MFMediaType_FileTransfer);

  IF_EQUAL_RETURN(guid, MFVideoFormat_AI44);             // FCC('AI44')
  IF_EQUAL_RETURN(guid, MFVideoFormat_ARGB32);           // D3DFMT_A8R8G8B8 
  IF_EQUAL_RETURN(guid, MFVideoFormat_AYUV);             // FCC('AYUV')
  IF_EQUAL_RETURN(guid, MFVideoFormat_DV25);             // FCC('dv25')
  IF_EQUAL_RETURN(guid, MFVideoFormat_DV50);             // FCC('dv50')
  IF_EQUAL_RETURN(guid, MFVideoFormat_DVH1);             // FCC('dvh1')
  IF_EQUAL_RETURN(guid, MFVideoFormat_DVSD);             // FCC('dvsd')
  IF_EQUAL_RETURN(guid, MFVideoFormat_DVSL);             // FCC('dvsl')
  IF_EQUAL_RETURN(guid, MFVideoFormat_H264);             // FCC('H264')
  IF_EQUAL_RETURN(guid, MFVideoFormat_I420);             // FCC('I420')
  IF_EQUAL_RETURN(guid, MFVideoFormat_IYUV);             // FCC('IYUV')
  IF_EQUAL_RETURN(guid, MFVideoFormat_M4S2);             // FCC('M4S2')
  IF_EQUAL_RETURN(guid, MFVideoFormat_MJPG);
  IF_EQUAL_RETURN(guid, MFVideoFormat_MP43);             // FCC('MP43')
  IF_EQUAL_RETURN(guid, MFVideoFormat_MP4S);             // FCC('MP4S')
  IF_EQUAL_RETURN(guid, MFVideoFormat_MP4V);             // FCC('MP4V')
  IF_EQUAL_RETURN(guid, MFVideoFormat_MPG1);             // FCC('MPG1')
  IF_EQUAL_RETURN(guid, MFVideoFormat_MSS1);             // FCC('MSS1')
  IF_EQUAL_RETURN(guid, MFVideoFormat_MSS2);             // FCC('MSS2')
  IF_EQUAL_RETURN(guid, MFVideoFormat_NV11);             // FCC('NV11')
  IF_EQUAL_RETURN(guid, MFVideoFormat_NV12);             // FCC('NV12')
  IF_EQUAL_RETURN(guid, MFVideoFormat_P010);             // FCC('P010')
  IF_EQUAL_RETURN(guid, MFVideoFormat_P016);             // FCC('P016')
  IF_EQUAL_RETURN(guid, MFVideoFormat_P210);             // FCC('P210')
  IF_EQUAL_RETURN(guid, MFVideoFormat_P216);             // FCC('P216'9
  IF_EQUAL_RETURN(guid, MFVideoFormat_RGB24);            // D3DFMT_R820B8 
  IF_EQUAL_RETURN(guid, MFVideoFormat_RGB32);            // D3DFMT_X820G8B8 
  IF_EQUAL_RETURN(guid, MFVideoFormat_RGB555);           // D3DFMT_X120G5B5 
  IF_EQUAL_RETURN(guid, MFVideoFormat_RGB565);           // D3DFMT_R520B5 
  IF_EQUAL_RETURN(guid, MFVideoFormat_RGB8);
  IF_EQUAL_RETURN(guid, MFVideoFormat_UYVY);             // FCC('UYVY')
  IF_EQUAL_RETURN(guid, MFVideoFormat_v210);             // FCC('v210')
  IF_EQUAL_RETURN(guid, MFVideoFormat_v410);             // FCC('v410')
  IF_EQUAL_RETURN(guid, MFVideoFormat_WMV1);             // FCC('WMV1')
  IF_EQUAL_RETURN(guid, MFVideoFormat_WMV2);             // FCC('WMV2')
  IF_EQUAL_RETURN(guid, MFVideoFormat_WMV3);             // FCC('WMV3')
  IF_EQUAL_RETURN(guid, MFVideoFormat_WVC1);             // FCC('WVC1')
  IF_EQUAL_RETURN(guid, MFVideoFormat_Y210);             // FCC('Y210')
  IF_EQUAL_RETURN(guid, MFVideoFormat_Y216);             // FCC('Y216')
  IF_EQUAL_RETURN(guid, MFVideoFormat_Y410);             // FCC('Y410')
  IF_EQUAL_RETURN(guid, MFVideoFormat_Y416);             // FCC('Y416')
  IF_EQUAL_RETURN(guid, MFVideoFormat_Y41P);
  IF_EQUAL_RETURN(guid, MFVideoFormat_Y41T);
  IF_EQUAL_RETURN(guid, MFVideoFormat_YUY2);             // FCC('YUY2')
  IF_EQUAL_RETURN(guid, MFVideoFormat_YV12);             // FCC('YV12')
  IF_EQUAL_RETURN(guid, MFVideoFormat_YVYU);

  IF_EQUAL_RETURN(guid, MFAudioFormat_PCM);              // WAVE_FORMAT_PCM 
  IF_EQUAL_RETURN(guid, MFAudioFormat_Float);            // WAVE_FORMAT_IEEE_FLOAT 
  IF_EQUAL_RETURN(guid, MFAudioFormat_DTS);              // WAVE_FORMAT_DTS 
  IF_EQUAL_RETURN(guid, MFAudioFormat_Dolby_AC3_SPDIF);  // WAVE_FORMAT_DOLBY_AC3_SPDIF 
  IF_EQUAL_RETURN(guid, MFAudioFormat_DRM);              // WAVE_FORMAT_DRM 
  IF_EQUAL_RETURN(guid, MFAudioFormat_WMAudioV8);        // WAVE_FORMAT_WMAUDIO2 
  IF_EQUAL_RETURN(guid, MFAudioFormat_WMAudioV9);        // WAVE_FORMAT_WMAUDIO3 
  IF_EQUAL_RETURN(guid, MFAudioFormat_WMAudio_Lossless); // WAVE_FORMAT_WMAUDIO_LOSSLESS 
  IF_EQUAL_RETURN(guid, MFAudioFormat_WMASPDIF);         // WAVE_FORMAT_WMASPDIF 
  IF_EQUAL_RETURN(guid, MFAudioFormat_MSP1);             // WAVE_FORMAT_WMAVOICE9 
  IF_EQUAL_RETURN(guid, MFAudioFormat_MP3);              // WAVE_FORMAT_MPEGLAYER3 
  IF_EQUAL_RETURN(guid, MFAudioFormat_MPEG);             // WAVE_FORMAT_MPEG 
  IF_EQUAL_RETURN(guid, MFAudioFormat_AAC);              // WAVE_FORMAT_MPEG_HEAAC 
  IF_EQUAL_RETURN(guid, MFAudioFormat_ADTS);             // WAVE_FORMAT_MPEG_ADTS_AAC 

  return("");
}

void get_sample(GLuint *out_texture, u32 *out_width, u32 *out_height)
{
  HRESULT hr = S_OK;

  IMFSourceResolver *source_resolver         = NULL;
  IUnknown          *source                  = NULL;
  IMFMediaSource    *media_file_source       = NULL;
  IMFAttributes     *video_reader_attributes = NULL;
  IMFSourceReader   *source_reader           = NULL;
  IMFMediaType      *reader_output_type      = NULL;
  IMFMediaType      *first_output_type       = NULL;
  MF_OBJECT_TYPE     object_type             = MF_OBJECT_INVALID;
  u32                mft_status              = 0;

  if (SUCCEEDED(hr))
  {
    hr = MFTRegisterLocalByCLSID(__uuidof(CColorConvertDMO), MFT_CATEGORY_VIDEO_PROCESSOR,
                                 L"", MFT_ENUM_FLAG_SYNCMFT, 0, NULL, 0, NULL);
  }

  // Set up the reader for the file.
  if (SUCCEEDED(hr))
  {
    hr = MFCreateSourceResolver(&source_resolver);
  }

  if (SUCCEEDED(hr))
  {
    hr = source_resolver->CreateObjectFromURL(L"big_buck_bunny.mp4", MF_RESOLUTION_MEDIASOURCE, NULL, &object_type, &source);
  }

  if (SUCCEEDED(hr))
  {
    hr = source->QueryInterface(IID_PPV_ARGS(&media_file_source));
  }

  if (SUCCEEDED(hr))
  {
    hr = MFCreateAttributes(&video_reader_attributes, 2);
  }

  if (SUCCEEDED(hr))
  {
    hr = video_reader_attributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
  }

  if (SUCCEEDED(hr))
  {
    hr = video_reader_attributes->SetUINT32(MF_SOURCE_READER_ENABLE_VIDEO_PROCESSING, 1);
  }

#if 0
  if (SUCCEEDED(hr))
  {
    GUID subtype_guid = {};
    video_reader_attributes->GetGUID(MF_MT_SUBTYPE, &subtype_guid);
    name = get_guid_name_const(subtype_guid);
  }

  GUID          guid       = {};
  char         *name       = "";
  IMFMediaType *media_type = NULL;
  hr = source_reader->GetNativeMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM,
                                         MF_SOURCE_READER_CURRENT_TYPE_INDEX,
                                         &media_type);

  hr = media_type->GetGUID(MF_MT_SUBTYPE, &guid);
  name = get_guid_name_const(guid);

#endif

  if (SUCCEEDED(hr))
  {
    hr = MFCreateSourceReaderFromMediaSource(media_file_source, video_reader_attributes, &source_reader);
  }

  if (SUCCEEDED(hr))
  {
    hr = MFCreateMediaType(&reader_output_type);
  }

  if (SUCCEEDED(hr))
  {
    hr = reader_output_type->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
  }

  if (SUCCEEDED(hr))
  {
    hr = reader_output_type->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_IYUV);
  }

  if (SUCCEEDED(hr))
  {
    hr = source_reader->SetCurrentMediaType(((DWORD) MF_SOURCE_READER_FIRST_VIDEO_STREAM), NULL, reader_output_type);
  }

  if (SUCCEEDED(hr))
  {
    hr = source_reader->GetCurrentMediaType(((DWORD) MF_SOURCE_READER_FIRST_VIDEO_STREAM), &first_output_type);
  }

  u32 frame_width  = 0;
  u32 frame_height = 0;
  hr = MFGetAttributeSize(first_output_type, MF_MT_FRAME_SIZE, (UINT32 *) &frame_width, (UINT32 *) &frame_height);

  // Start processing frames.
  IMFSample* video_sample     = NULL;
  u32        stream_index     = 0;
  u32        flags            = 0;
  u64        video_time_stamp = 0;
  u64        sample_duration  = 0;
  s32        sample_count     = 0;
  u32        sample_flags     = 0;

  hr = source_reader->ReadSample(MF_SOURCE_READER_FIRST_VIDEO_STREAM,
                                 0,
                                 (DWORD *) &stream_index,
                                 (DWORD *) &flags,
                                 (LONGLONG *) &video_time_stamp,
                                 &video_sample);

  if (SUCCEEDED(hr))
  {
    if (flags & MF_SOURCE_READERF_STREAMTICK)
    {
      printf("\tStream tick.\n");
    }

    if (flags & MF_SOURCE_READERF_ENDOFSTREAM)
    {
      printf("\tEnd of stream.\n");
    }

    if (flags & MF_SOURCE_READERF_NEWSTREAM)
    {
      printf("\tNew stream.\n");
    }

    if (flags & MF_SOURCE_READERF_NATIVEMEDIATYPECHANGED)
    {
      printf("\tNative type changed.\n");
    }

    if (flags & MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED)
    {
      printf("\tCurrent type changed.\n");
    }

    if (video_sample)
    {
      if (SUCCEEDED(hr))
      {
        video_sample->SetSampleTime(video_time_stamp);
      }

      if (SUCCEEDED(hr))
      {
        video_sample->GetSampleDuration((LONGLONG *) &sample_duration);
      }

      if (SUCCEEDED(hr))
      {
        video_sample->GetSampleFlags((DWORD *) &sample_flags);
      }

      IMFMediaBuffer *media_buffer          = NULL;
      u8             *frame_data            = NULL;
      u32             buffer_length         = 0;
      u32             buffer_max_length     = 0;
      u32             buffer_current_length = 0;

      hr = video_sample->ConvertToContiguousBuffer(&media_buffer);
      hr = media_buffer->GetCurrentLength((DWORD *) &buffer_length);
      hr = media_buffer->Lock(&frame_data, (DWORD *) &buffer_max_length, (DWORD *) &buffer_current_length);

      GLuint image_texture;
      glGenTextures(1, &image_texture);
      glBindTexture(GL_TEXTURE_2D, image_texture);

      // Setup filtering parameters for display
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

      // Upload pixels into texture
      glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, frame_width, frame_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, frame_data);

      hr = media_buffer->Unlock();

      if (SUCCEEDED(hr))
      {
        *out_texture = image_texture;
        *out_width   = frame_width;
        *out_height  = frame_height;
      }
    }
  }
}
