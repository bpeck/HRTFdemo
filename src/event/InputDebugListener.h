#ifndef __INPUTDEBUGLISTENER_H__
#define __INPUTDEBUGLISTENER_H__

#include "EventListener.h"

#include <SDL2/SDL.h>

class InputDebugListener : public EventListener {
    public:
        bool done;
        
        InputDebugListener() {
            done = false;
        }
    
        void OnEvent(SDL_Event& event, Uint32 dT) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    printf("The %s key was pressed!\n",
                        SDL_GetKeyName(event.key.keysym.sym));
                    
                    if(event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q) {
                        done = true;
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
};

#endif // __INPUTDEBUGLISTENER_H__
