#include "PauseState.h"
#include "MenuState.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "GameSettings.h"

const std::string PauseState::pauseID = "PAUSE";

void PauseState::onMainMenuClick()
{

	Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::onResumeClick()
{
	Game::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for (auto obj : gameObjects)
		if(obj) obj->update();
}

void PauseState::render()
{
	for (auto obj : gameObjects)
		if(obj) obj->draw();
}

bool PauseState::onEnter()
{
	if (!TextureManager::Instance()->load("imgs/resume.png", "resumebutton"))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("imgs/mainmenu.png", "mainbutton" ))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2 - 100,
		120, 50, "mainbutton"), &onMainMenuClick);
	gameObjects.push_back(button1);

	GameObject* button2 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2,
		120, 50, "resumebutton"), &onResumeClick);
	gameObjects.push_back(button2);

	return true;
}

bool PauseState::onExit()
{
	for (auto obj : gameObjects)
	{
		obj->clean();
	}

	gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("resumebutton");
	TextureManager::Instance()->clearFromTextureMap("mainbutton");

	return true;
}

