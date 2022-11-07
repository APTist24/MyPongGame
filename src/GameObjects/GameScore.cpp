#include "GameScore.h"
#include "SDL.h"
#include "TextureManager.h"
#include "GameOverState.h"


GameScore::GameScore(const LoaderParams* pParams) : GameObject(pParams)
{
	rect = { pParams->getX(), pParams->getY(), pParams->getWidth(),pParams->getHeight() };
	scoreTexture = TextureManager::Instance()->createTextureFromText("0");
}

void GameScore::draw()
{
	SDL_QueryTexture(scoreTexture, nullptr, nullptr,  &rect.w, &rect.h);
	SDL_RenderCopy(Game::Instance()->getRenderer(), scoreTexture, nullptr, &rect);

}

void GameScore::IncreaseScore(const uint8_t playerID)
{
	++score;
	if (score > 9)
		Game::Instance()->getStateMachine()->changeState(std::move(std::make_unique<GameOverState>(playerID)));
	else scoreTexture = TextureManager::Instance()->createTextureFromText(std::to_string(score));
}