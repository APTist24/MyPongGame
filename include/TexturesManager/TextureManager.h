// #pragma once
//
// #include <string>
// #include <map>
// #include <SDL3/SDL.h>
// #include "SDL_ttf.h"
// #include <SDL3/SDL_image.h>
// #include <iostream>
// #include "Game.h"
//
// class TextureManager
// {
// public:
//
// 	TextureManager(TextureManager&) = delete;
// 	void operator=(const TextureManager&) = delete;
//
// 	static TextureManager* Instance();
//
// 	bool load(std::string fileName, std::string id)
// 	{
// 		SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
// 		if (!pTempSurface)
// 		{
// 			std::cerr << "Unable to create a surface "  << std::endl;
// 			return false;
// 		}
// 		SDL_Texture* pTexture =
// 			SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), pTempSurface);
// 		SDL_FreeSurface(pTempSurface);
//
// 		if (pTexture)
// 		{
// 			textureMap[id] = pTexture;
// 			return true;
// 		}
// 	    //something wrong if we here
// 		std::cerr << "Unable to create texture from a surface: " << SDL_GetError() << std::endl;
// 		return false;
// 	}
//
// 	SDL_Texture* createTextureFromText(std::string text)
// 	{
// 		SDL_Color color{ 0xff, 0xff, 0xff, 0xff };
// 		auto surface = TTF_RenderText_Blended(Game::Instance()->getFont(), text.c_str(), color);
// 		if (!surface) {
// 			std::cerr << "Unable to create a surface with a text: " << TTF_GetError() << std::endl;
// 			return nullptr;
// 		}
//
// 		// create a texture from the text surface.
// 		auto texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surface);
// 		SDL_FreeSurface(surface);
// 		if (!texture) {
// 			std::cerr << "Unable to create texture from a text surface: " << SDL_GetError() << std::endl;
// 			return nullptr;
// 		}
// 		return texture;
// 	}
//
// 	void draw(std::string id, int x, int y, int
// 		width, int height, SDL_Renderer* pRenderer,
// 		SDL_RendererFlip flip)
// 	{
// 		SDL_Rect srcRect;
// 		SDL_Rect destRect;
//
// 		srcRect.x = 0;
// 		srcRect.y = 0;
// 		srcRect.w = destRect.w = width;
// 		srcRect.h = destRect.h = height;
//
// 		destRect.x = x;
// 		destRect.y = y;
//
// 		SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
// 			&destRect, 0, 0, flip);
// 	}
//
// 	void drawFrame(std::string id, int x, int y, int
// 		width, int height, int currentRow, int currentFrame, SDL_Renderer
// 		* pRenderer, SDL_RendererFlip flip)
// 	{
//
// 		SDL_Rect srcRect;
// 		SDL_Rect destRect;
//
// 		srcRect.x = width * currentFrame;
// 		srcRect.y = height * (currentRow - 1);
//
// 		srcRect.w = destRect.w = width;
// 		srcRect.h = destRect.h = height;
//
// 		destRect.x = x;
// 		destRect.y = y;
// 		SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect,
// 			&destRect, 0, 0, flip);
//
// 	}
//
// 	void clearFromTextureMap(std::string id)
// 	{
// 			textureMap.erase(id);
// 	}
//
// private:
// 	TextureManager() {}
// 	std::map<std::string, SDL_Texture*> textureMap;
//
// 	static TextureManager* s_pInstance;
// };
//
//
