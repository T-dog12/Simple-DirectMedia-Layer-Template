#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int SDL_main(int argc, char* argv[])
{
	SDL_Window* Window;
	bool end = false;

	// Initializes visuals
	SDL_Init(SDL_INIT_VIDEO);

	Window = SDL_CreateWindow("SDL TEMPLATE WINDOW!", 640, 480, SDL_WINDOW_OPENGL);
	if (Window == NULL)
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "COULD NOT CREATE WINDOW : %s\n ", SDL_GetError());
		return -1;	
	}


	while (!end)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_EVENT_QUIT) { end = true; }
		}
	}
	SDL_DestroyWindow(Window);

	SDL_Quit();
	return 0;
}