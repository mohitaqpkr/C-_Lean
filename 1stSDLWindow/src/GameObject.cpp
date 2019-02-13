#pragma once
#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char * texturesheet, int x, int y, int srcRectH, int srcRectW)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
	srcRect.h = srcRectH;
	srcRect.w = srcRectW;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;


	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;


}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
