#ifndef __EVENTDISPATCH_H__
#define __EVENTDISPATCH_H__

#include "EventListener.h"
#include <list>
#include <SDL2/SDL.h>

class EventDispatch {
    public:
        EventDispatch(int m_numEventsToProcessPerUpdate=10);
    
        void AddListener(EventListener& listener);
        void RemoveListener(EventListener& listener);
        
        // Returns true if processed an event, false if no event polled
        bool PollEvents(Uint32 dT);
        
    private:
        int numEventsToPollPerUpdate;
        std::list<EventListener*> listeners;
};
#endif // EVENTDISPATCH
