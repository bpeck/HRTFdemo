#ifndef __SDLINCLUDES_H__
#define __SDLINCLUDES_H__

/* If using gl3.h */
/* Ensure we are using opengl's core profile only */
#define GL3_PROTOTYPES 1

/*
 #ifdef __APPLE__  // include Mac OS X verions of headers
#  include <OpenGL/OpenGL.h>
#else // non-Mac OS X operating systems
#  include <GL/glew.h>
#endif  // __APPLE__
 */

#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL.h>

#endif // __SDLINCLUDES_H__
