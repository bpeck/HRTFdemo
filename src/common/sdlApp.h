#ifndef __SDL_APP__
#define __SDL_APP__

#include "pbn.h"
#include "../event/EventDispatch.h"

#include <string>

class sdlApp {
    public:
        sdlApp(std::string name="SDL App",
               int w=512, int h=512,
               GLuint GLMajorV=3, GLuint GLMinorV=3, GLuint GLProfile=SDL_GL_CONTEXT_PROFILE_CORE,
               GLuint zBuffBitDepth=24, Uint32 EventRate=17, Uint32 RenderRate=17);
        
        int Main();
        
        virtual void Init() = 0;
        virtual void Mainloop() = 0;
        virtual void Teardown() = 0;
    
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
