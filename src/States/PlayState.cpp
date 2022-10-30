#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Player.h"
#include "Enemy.h"
#include "GameSettings.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->update();
	}

	//if (checkCollision(dynamic_cast<GameObject*>
	//	(gameObjects[0]), dynamic_cast<GameObject*>
	//	(gameObjects[1])))
	{
		//Game::Instance()->getStateMachine()->pushState(new GameOverState());
	}
}

void PlayState::render()
{
	for (auto obj : gameObjects)
		if(obj) obj->draw();
}
bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load("imgs/player.png",
		"player", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(new LoaderParams(0, 100, 25, 150, "player"));
	gameObjects.push_back(player);

	GameObject* enemy = new Enemy(new LoaderParams(WIDTH - 25, 100, 25, 150, "player"));
	gameObjects.push_back(enemy);

	return true;
}


bool PlayState::onExit()
{
	for (auto obj : gameObjects)
		if(obj) obj->clean();

	gameObjects.clear();

	return true;
}

bool PlayState::checkCollision(GameObject* p1, GameObject*
	p2)
{
	return false;
}
