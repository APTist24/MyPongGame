#include "GameOverState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "GameSettings.h"
#include "PlayState.h"
#include "MenuState.h"

const std::string GameOverState::gameOverID = "GAMEOVER";


GameOverState::GameOverState(uint8_t playerID_) : 
												GameState(),
												playerID(playerID_)
{

}

void GameOverState::update()
{
	for (auto obj : gameObjects)
		if (obj) obj->update();
}

void GameOverState::render()
{
	for (auto obj : gameObjects)
		if (obj) obj->draw();
}

bool GameOverState::onEnter()
{
	if (!TextureManager::Instance()->load("imgs/start.png",
		"playbutton"))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("imgs/exit.png",
		"exitbutton"))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2 - 50,
		135, 35, "playbutton"), &onPlayPress);
	gameObjects.push_back(button1);

	GameObject* button2 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2,
		135, 35, "exitbutton"), &onMenuPress);
	gameObjects.push_back(button2);

	//ADD TEXT WHO WIN

	return true;
}

bool GameOverState::onExit()
{
	for (auto obj : gameObjects)
		if (obj) obj->clean();

	gameObjects.clear();

	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");

	return true;
}

void GameOverState::onPlayPress()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::onMenuPress()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}

