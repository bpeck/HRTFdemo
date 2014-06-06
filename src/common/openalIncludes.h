//
//  openalIncludes.h
//  HRTF_Demo
//
//  Created by Ben Peck on 6/5/14.
//
//

#ifndef HRTF_Demo_openalIncludes_h
#define HRTF_Demo_openalIncludes_h

#include <SDL2/SDL.h>

// Without this, it doesn't prototype the functions that OpenAL-Mob adds to the reference implementation.
#define AL_ALEXT_PROTOTYPES
#include <AL/al.h>
#include <AL/alext.h>
#include <alConfigMob.h>

const MOB_ConfigKeyValue g_soundConfig[] =
{
#if PLAT_WIN
    // The default sound output on Windows can't be forced to 44.1 KHz. Outputting at 44.1 KHz is essential to support HRTF, so adding this is on Windows is a good idea
    { MOB_ConfigKey_root_drivers , "dsound" },
#endif // #if PLAT_WIN
    // If you want to use HRTFs, you should be outputting to Stereo sound
    { MOB_ConfigKey_root_channels, "stereo" },
    { MOB_ConfigKey_root_hrtf    , (const char*)1 }, // This is a union, and const char * is the first type, so we have to cast it.
    { MOB_ConfigKey_NULL         , 0 }, // This is the terminator for the config array
};

void initOpenAL( ALCdevice* &device, ALCcontext* &context )
{
    // Before you call alcOpenDevice, set your config
    alSetConfigMOB( g_soundConfig );
    device = alcOpenDevice(NULL);
    
    // the parameters
    const ALint params[] =
    {
        ALC_FREQUENCY, 44100,   // The HRTF only works for 44.1KHz output.
        0,          // Null terminator
    };
    context = alcCreateContext(device, params);
    alcMakeContextCurrent(context);
}

ALuint loadWAV(const char* filename)
{
    SDL_AudioSpec wav_spec;
    Uint32 wav_length;
    Uint8 *wav_buffer;
    
    /* Load the WAV */
    if (SDL_LoadWAV(filename, &wav_spec, &wav_buffer, &wav_length) == NULL) {
        printf("Could not open test.wav: %s\n", SDL_GetError());
        return 0;
    }
    ALuint buffer = -1;
    alGenBuffers((ALuint)1, &buffer);
    
    bool stereo = (wav_spec.channels > 1);
    Uint32 internalFormat = 0;
    int bitsPerSample = SDL_AUDIO_BITSIZE(wav_spec.format);
    if (bitsPerSample == 16) {
        if (stereo)
            internalFormat = AL_FORMAT_STEREO16;
        else
            internalFormat = AL_FORMAT_MONO16;
    }
    else {
        if (stereo)
            internalFormat = AL_FORMAT_STEREO8;
        else
            internalFormat = AL_FORMAT_MONO8;
    }
    
    alBufferData(buffer, internalFormat, wav_buffer, wav_length, wav_spec.freq);
    
    //SDL_FreeWAV(wav_buffer);
    
    return buffer;
}


#endif
