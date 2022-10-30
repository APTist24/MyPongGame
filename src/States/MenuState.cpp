#include "MenuState.h"
#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "GameSettings.h"
#include "PlayState.h"

const std::string MenuState::menuID = "MENU";

void MenuState::update()
{
	for (auto obj : gameObjects)
		if (obj) obj->update();
}

void MenuState::render()
{
	for (auto obj : gameObjects)
		if (obj) obj->draw();
}

bool MenuState::onEnter()
{
	if (!TextureManager::Instance()->load("imgs/start.png",
		"playbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("imgs/exit.png",
		"exitbutton", Game::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2 -50,
		135, 35, "playbutton"), &onPlayPress);
	gameObjects.push_back(button1);

	GameObject* button2 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2,
		135, 35, "exitbutton"), &onQuitPress);
	gameObjects.push_back(button2);

	return true;
}

bool MenuState::onExit()
{
	for (auto obj : gameObjects)
		if (obj) obj->clean();

	gameObjects.clear();

	TextureManager::Instance()->clearFromTextureMap("playbutton");
	TextureManager::Instance()->clearFromTextureMap("exitbutton");

	return true;
}

void MenuState::onPlayPress()
{
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::onQuitPress()
{
	Game::Instance()->quit();
}

