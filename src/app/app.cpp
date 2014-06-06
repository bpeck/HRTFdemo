#include "app.h"

// PBN
#include "../event/EventDispatch.h"
#include "../event/EventListener.h"

#include "../common/openalIncludes.h"

ALCdevice* device;
ALCcontext* context;

ALuint source;
ALuint buffer;

app::app() :
    sdlApp(),
    EventListener(),
    done(false)
{
}

void app::init() {
    initOpenAL(device, context);
    
    // setup event listener that prints out keyboard and mouse clicks
    this->eventDispatch.AddListener(*this);
}

void app::teardown() {
}

void app::render(float dT) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    SDL_GL_SwapWindow(this->windowHandle);
}

void app::mainloop() {
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
            render(renderDt);
            lastRenderUpdate = SDL_GetTicks();
        }
    }
}

void app::OnEvent(SDL_Event& event, Uint32 dT) {
    switch(event.type) {
        case SDL_KEYDOWN:
            printf("The %s key was pressed!\n",
                   SDL_GetKeyName(event.key.keysym.sym));
            
            if(event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q) {
                this->done = true;
            }
            
            break;
            //                case SDL_MOUSEMOTION:
            //                    printf("Mouse moved by %d,%d to (%d,%d)\n",
            //                        event.motion.xrel, event.motion.yrel,
            //                        event.motion.x, event.motion.y);
            //                    break;
        case SDL_MOUSEBUTTONDOWN:
            printf("Mouse button %d pressed at (%d,%d)\n",
                   event.button.button, event.button.x, event.button.y);
            break;
            
        case SDL_QUIT:
            exit(0);
    }
}
