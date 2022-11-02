#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Player.h"
#include "Enemy.h"
#include "Ball.h"
#include "GameScore.h"
#include "GameSettings.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (auto obj: gameObjects)
		if(obj) obj->update();

	if (checkCollision(enemy))
		ball->getVelocity().setX(-BALL_SPEED);
	if (checkCollision(player))
		ball->getVelocity().setX(BALL_SPEED);

}

void PlayState::render()
{
	for (auto obj : gameObjects)
		if(obj) obj->draw();
	//draw central line
	
}
bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load("imgs/player.png",
		"player", Game::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TextureManager::Instance()->load("imgs/ball.png",
		"ball", Game::Instance()->getRenderer()))
	{
		return false;
	}

	player = new Player(new LoaderParams(0, 100, 25, 150, "player"));
	gameObjects.push_back(player);

	enemy = new Enemy(new LoaderParams(WIDTH - 25, 100, 25, 150, "player"));
	gameObjects.push_back(enemy);

	ball = new Ball(new LoaderParams(WIDTH / 2, HEIGHT /2, 15, 15, "ball"), this);
	gameObjects.push_back(ball);

	playerScore = new GameScore(new LoaderParams(WIDTH / 4, HEIGHT / 5, 50, 50, "player"));
	gameObjects.push_back(playerScore);

	enemyScore = new GameScore(new LoaderParams((WIDTH/ 2) + WIDTH / 4, HEIGHT / 5, 50, 50, "player"));
	gameObjects.push_back(enemyScore);

	return true;
}


bool PlayState::onExit()
{
	for (auto obj : gameObjects)
		if(obj) obj->clean();

	gameObjects.clear();

	return true;
}

bool PlayState::checkCollision(GameObject* obj) //with ball
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = obj->getPosition().getX();
	rightA = obj->getPosition().getX() + obj->getWidth();
	topA = obj->getPosition().getY();
	bottomA = obj->getPosition().getY() + obj->getHeight();

	//Calculate the sides of rect Ball
	leftB = ball->getPosition().getX();
	rightB = ball->getPosition().getX() + ball->getWidth();
	topB = ball->getPosition().getY();
	bottomB = ball->getPosition().getY() + ball->getHeight();

	//If any of the sides from A are outside of Ball
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

void PlayState::Goal(const uint8_t playerID)
{
	//playerID = 0, enemyID = 1
	!playerID ? playerScore->IncreaseScore() : enemyScore->IncreaseScore();
}

