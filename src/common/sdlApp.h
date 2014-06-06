#ifndef __SDL_APP__
#define __SDL_APP__

#include "pbn.h"
#include "../event/EventDispatch.h"

#include <string>

class sdlApp {
    public:
        sdlApp(std::string name="SDL App", int w=512, int h=512, int GLMajorV=4, int GLMinorV=0,
               int zBuffBitDepth=24, Uint32 EventRate=17, Uint32 RenderRate=17);
        
        int Main();
        
        virtual void init() = 0;
        virtual void mainloop() = 0;
        virtual void teardown() = 0;
    
    protected:
        std::string appName;
        int width;
        int height;
        Uint32 eventPollRate;
        Uint32 renderRate;

        EventDispatch eventDispatch;
        
        SDL_GLContext glContext;
        SDL_Window *windowHandle;
};

#endif
