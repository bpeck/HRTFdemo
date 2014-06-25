#ifndef __SDLTEST_H__
#define __SDLTEST_H__

#include "../common/sdlApp.h"
#include "../event/EventListener.h"

class app : public sdlApp, EventListener {
    public:
        app();
        
        void Init();
        void Render(float dT);
        void Mainloop();
        void Teardown();
    
        void OnEvent(SDL_Event& event, Uint32 dT);
    
    private:
        void _moveSoundSource(int mousex, int mousey);
        bool done;
};

#endif
