#pragma once

#include "Game.h"

class GameObject {

public:
	GameObject(const char *texturesheet, int x, int y, int srcRectH, int srcRectW);
	~GameObject();

	void Update();
	void Render();

private:
	int xpos;
	int ypos;

	SDL_Texture *objTexture;
	SDL_Rect srcRect, destRect;
};