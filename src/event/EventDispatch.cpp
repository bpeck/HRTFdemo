#include "EventDispatch.h"
#include "EventListener.h"
#include <list>
#include <SDL2/SDL.h>

EventDispatch::EventDispatch(int m_numEventsToProcessPerUpdate) :
    numEventsToPollPerUpdate(m_numEventsToProcessPerUpdate)
{
    listeners.clear();
}

void EventDispatch::AddListener(EventListener& listener) {
    listeners.push_back(&listener);
}

void EventDispatch::RemoveListener(EventListener& listener) {
    listeners.remove(&listener);
}

bool EventDispatch::PollEvents(Uint32 dT) {
    SDL_Event event;
    int numEventsProcessed = 0;
    
    while(numEventsProcessed < numEventsToPollPerUpdate && SDL_PollEvent(&event)) {
        std::list<EventListener*>::iterator it;
        for(it = listeners.begin(); it != listeners.end(); it++) {
            (*it)->OnEvent(event, dT);
        }
    }
    
    return numEventsProcessed > 0;
}
