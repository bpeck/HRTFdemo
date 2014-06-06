#ifndef __SDLUTIL_H__
#define __SDLUTIL_H__

/* A simple function that prints a message, the error code returned by SDL,
 * and quits the application */
void SDLdie(const char *msg)
{
    printf("%s: %s\n", msg, SDL_GetError());
    SDL_Quit();
    exit(1);
}
 
 
void CheckSDLError(int line = -1)
{
#ifdef DEBUG
	const char *error = SDL_GetError();
	if (*error != '\0')
	{
		printf("SDL Error: %s\n", error);
		if (line != -1)
			printf(" + line: %i\n", line);
		SDL_ClearError();
	}
#endif
}

#endif
