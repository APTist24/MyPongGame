#ifndef __TextureManager__
#define __TextureManager__

#include <string>
#include <map>
#include "SDL.h"
#include <SDL_image.h>

class TextureManager
{
public:

	TextureManager(TextureManager&) = delete;
	void operator=(const TextureManager&) = delete;

	static TextureManager* Instance();

	bool load(std::string fileName, std::string
		id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int
		width, int height, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip);

	void drawFrame(std::string id, int x, int y, int
		width, int height, int currentRow, int currentFrame, SDL_Renderer
		* pRenderer, SDL_RendererFlip flip)
	{

		SDL_Rect srcRect;
		SDL_Rect destRect;

		srcRect.x = width * currentFrame;
		srcRect.y = height * (currentRow - 1);

		srcRect.w = destRect.w = width;
		srcRect.h = destRect.h = height;

		destRect.x = x;
		destRect.y = y;
		SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
			&destRect, 0, 0, flip);

	}

	void clearFromTextureMap(std::string id);

private:
	TextureManager() {}

	std::map<std::string, SDL_Texture*> textureMap;

	static TextureManager* s_pInstance;
};


#endif