#include <unistd.h>

#include "app.h"

// PBN
#include "../event/EventDispatch.h"
#include "../event/EventListener.h"

#include "../common/openalIncludes.h"

ALCdevice* device;
ALCcontext* context;

ALuint source;
ALuint buffer;

const float ROOM_WIDTH = 10.f;
const float ROOM_HEIGHT = ROOM_WIDTH;

app::app() :
    sdlApp("HRTF Test - Put on Headphones & Move mouse around"),
    EventListener(),
    done(false)
{
    char buff[512];
    getcwd(buff, 511);
    printf("Working Directory: %s\n", buff);
}

void app::Init() {
    initOpenAL(device, context);
    
    alGenSources((ALuint)1, &source);
    alSourcef(source, AL_PITCH, 1);
    alSourcef(source, AL_GAIN, 1);
    alSource3f(source, AL_POSITION, 0, 0, 0);
    alSource3f(source, AL_VELOCITY, 0, 0, 0);
    // distance below which sound is no attenuated up any further
    alSourcei(source, AL_REFERENCE_DISTANCE, 0.05);
    // distance above which sound is not attenuated down any further
    alSourcei(source, AL_MAX_DISTANCE, ROOM_WIDTH * 0.95);
    alSourcei(source, AL_LOOPING, AL_TRUE);
    
    buffer = loadWAV("data/test.wav");
    alSourcei(source, AL_BUFFER, buffer);
    
    alSourcePlay(source);
    
    // setup event listener that prints out keyboard and mouse clicks
    this->eventDispatch.AddListener(*this);
}

void app::Teardown() {
    // cleanup OpenAL
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
    device = alcGetContextsDevice(context);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);
}

void app::Render(float dT) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    SDL_GL_SwapWindow(this->windowHandle);
}

void app::Mainloop() {
    Uint32 lastRenderUpdate = SDL_GetTicks();
    Uint32 lastEventPoll = SDL_GetTicks();
    
    while(!this->done) {
        // is it time to poll for mouse / keyboard?
        Uint32 eventDt = SDL_GetTicks() - lastEventPoll;
        if (eventDt > this->eventPollRate) {
            this->eventDispatch.PollEvents(eventDt);
            lastEventPoll = SDL_GetTicks();
        }
        // is it time to render?
        Uint32 renderDt = SDL_GetTicks() - lastRenderUpdate;
        if (renderDt > this->renderRate) {
            this->Render(renderDt);
            lastRenderUpdate = SDL_GetTicks();
        }
    }
}

void app::OnEvent(SDL_Event& event, Uint32 dT) {
    switch(event.type) {
        case SDL_KEYDOWN:
            //printf("The %s key was pressed!\n",
            //       SDL_GetKeyName(event.key.keysym.sym));
            
            if(event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q) {
                this->done = true;
            }
            
            break;
        case SDL_MOUSEMOTION:
            this->_moveSoundSource(event.motion.x, event.motion.y);
            break;
        case SDL_QUIT:
            exit(0);
    }
}

void app::_moveSoundSource(int mousex, int mousey) {
    int winW, winH;
    SDL_GetWindowSize(this->windowHandle, &winW, &winH);
    float wx = (-0.5f + ((float)mousex / (float)winW)) * ROOM_WIDTH;
    float wz = (-0.5f + ((float)mousey / (float)winH)) * ROOM_HEIGHT;
    
    alSource3f(source, AL_POSITION, wx, wz, 0);
}
