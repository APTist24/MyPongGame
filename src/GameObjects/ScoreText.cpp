// #include "ScoreText.h"
// #include "TextureManager.h"
//
//
// ScoreText::ScoreText(const LoaderParams* pParams, const std::string& text) : GameObject(pParams)
// {
// 	rect = { pParams->getX(), pParams->getY(), pParams->getWidth(),pParams->getHeight() };
// 	sdlTexture = TextureManager::Instance()->createTextureFromText(text);
// }
//
// void ScoreText::draw()
// {
// 	SDL_QueryTexture(sdlTexture, nullptr, nullptr, &rect.w, &rect.h);
// 	SDL_RenderCopy(Game::Instance()->getRenderer(), sdlTexture, nullptr, &rect);
//
// }