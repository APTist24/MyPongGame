#include "GameOverTexture.h"
#include "TextureManager.h"


GameOverTexture::GameOverTexture(const LoaderParams* pParams, const std::string& text) : GameObject(pParams)
{
	rect = { pParams->getX(), pParams->getY(), pParams->getWidth(),pParams->getHeight() };
	sdlTexture = TextureManager::Instance()->createTextureFromText(text);
}

void GameOverTexture::draw()
{
	SDL_QueryTexture(sdlTexture, nullptr, nullptr, &rect.w, &rect.h);
	SDL_RenderCopy(Game::Instance()->getRenderer(), sdlTexture, nullptr, &rect);

}