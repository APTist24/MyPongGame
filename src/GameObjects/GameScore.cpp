#include "GameScore.h"
#include "SDL.h"
#include "TextureManager.h"


GameScore::GameScore(const LoaderParams* pParams, SDL_Rect rect_) : GameObject(pParams), rect(rect_)
{
	scoreTexture = TextureManager::Instance()->createTextureFromText("0");
}

void GameScore::draw()
{
	SDL_QueryTexture(scoreTexture, nullptr, nullptr,  &rect.w, &rect.h);
	//rect.x = (400 - (rect.w / 2));
	SDL_RenderCopy(Game::Instance()->getRenderer(), scoreTexture, nullptr, &rect);

}

void GameScore::update() 
{

};

void GameScore::IncreaseScore()
{
	scoreTexture = TextureManager::Instance()->createTextureFromText(std::to_string(++score));
}