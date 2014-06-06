#ifndef __EVENTLISTENER_H__
#define __EVENTLISTENER_H__

#include <SDL2/SDL.h>

class EventListener {
    public:
        EventListener() {};
        
        virtual void OnEvent(SDL_Event& event, Uint32 dT) = 0;
};

#endif // EVENTLISTENER

