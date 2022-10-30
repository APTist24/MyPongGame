#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = nullptr;

TextureManager* TextureManager::Instance()
{
	if (s_pInstance == nullptr)
		s_pInstance = new TextureManager();
	return s_pInstance;
}

bool TextureManager::load(std::string fileName, std::string
	id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == nullptr)
	{
		return false;
	}
	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	// everything went ok, add the texture to our list
	if (pTexture != nullptr)
	{
		textureMap[id] = pTexture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int
	width, int height, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}

//void TextureManager::drawFrame(std::string id, int x, int y, int
//	width, int height, int currentRow, int currentFrame, SDL_Renderer
//	* pRenderer, SDL_RendererFlip flip)
//{
//	SDL_Rect srcRect;
//	SDL_Rect destRect;
//
//	srcRect.x = width * currentFrame;
//	srcRect.y = height * (currentRow - 1);
//
//	srcRect.w = destRect.w = width;
//	srcRect.h = destRect.h = height;
//
//	destRect.x = x;
//	destRect.y = y;
//	SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
//		&destRect, 0, 0, flip);
//}

void TextureManager::clearFromTextureMap(std::string id)
{
	textureMap.erase(id);
}