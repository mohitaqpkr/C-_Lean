#include <SDL.h>
#include "Game.h"
#undef main

Game *game = nullptr;

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart = 0;
	int FrameTime = 0;

	game = new Game();
	game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		FrameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > FrameTime) {
			SDL_Delay(frameDelay - FrameTime);
		}

	}

	game->clean();

	return 0;
}