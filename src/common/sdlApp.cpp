#include "sdlApp.h"
#include "sdlIncludes.h"
#include "sdlUtil.h"
#include "../event/EventDispatch.h"
#include <string>

sdlApp::sdlApp(std::string name, int w, int h,
    GLuint GLMajorV, GLuint GLMinorV, GLuint GLProfile, GLuint zBuffBitDepth,
    Uint32 EventRate, Uint32 RenderRate) :
    appName(name),
    width(w),
    height(h),
    eventPollRate(EventRate),
    renderRate(RenderRate)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
        SDLdie("Unable to initialize SDL"); /* Or die on error */
    
    /* Request opengl context. */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GLMajorV);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GLMinorV);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, GLProfile);
 
    /* Turn on double buffering with a 24bit Z buffer.
     * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, zBuffBitDepth);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
 
    /* Create our window centered at 512x512 resolution */
    windowHandle = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!windowHandle) /* Die if creation failed */
        SDLdie("Unable to create window");
 
    CheckSDLError(__LINE__);
 
    /* Create our opengl context and attach it to our window */
    glContext = SDL_GL_CreateContext(windowHandle);
    CheckSDLError(__LINE__);
    
    GLint profileMask;
    glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &profileMask);
    fprintf(
        stdout,
        "INFO: OpenGL Version: %s, profile mask %d\n",
        glGetString(GL_VERSION), profileMask
    );
 
 
    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);
 
    /* Swap our back buffer to the front */
    SDL_GL_SwapWindow(windowHandle);
}

int sdlApp::Main() {
    this->Init();
 
    this->Mainloop();
    
    this->Teardown();
    
    /* Delete our opengl context, destroy our window, and shutdown SDL */
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(windowHandle);
    SDL_Quit();
    
    return 0;
}

