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

	checkWallCollision();

	if (checkCollision(enemy)) {
		auto ballPtr = static_cast<Ball*>(ball);
		auto ballSpeed = ballPtr->getSpeed();
		auto maxBallSpeed = ballPtr->getSpeedLimit();
		ball->getVelocity().setX(-ballSpeed);
		if (ballSpeed < maxBallSpeed)
			ballPtr->setSpeed(++ballSpeed);
	}
	if (checkCollision(player)) {
		auto ballPtr = static_cast<Ball*>(ball);
		auto ballSpeed = ballPtr->getSpeed();
		auto maxBallSpeed = ballPtr->getSpeedLimit();
		ball->getVelocity().setX(ballSpeed);
		if (ballSpeed < maxBallSpeed)
			ballPtr->setSpeed(++ballSpeed);
	}

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

	ball = new Ball(new LoaderParams(WIDTH / 2, HEIGHT / 2, 15, 15, "ball"));
	gameObjects.push_back(ball);

	enemy = new Enemy(new LoaderParams(WIDTH - 25, 100, 25, 150, "player"), ball);
	gameObjects.push_back(enemy);

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

bool PlayState::checkCollision(GameObject* obj)
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
	if (bottomA <= topB) 
		return false; 
	if (topA >= bottomB) 
		return false;
	if (rightA <= leftB) 
		return false;
	if (leftA >= rightB)  
		return false; 

	return true;
}

void PlayState::checkWallCollision()
{
	int leftB = ball->getPosition().getX();
	int rightB = ball->getPosition().getX() + ball->getWidth();
	int topB = ball->getPosition().getY();
	int bottomB = ball->getPosition().getY() + ball->getHeight();

	auto ballSpeed = static_cast<Ball*>(ball)->getSpeed();
	//top
	if (topB < 0)
	{
		ball->getVelocity().setY(ballSpeed);
		return;
	}
	//bot
	if (bottomB > HEIGHT)
	{
		ball->getVelocity().setY(-ballSpeed);
		return;
	}
	//ai side
	if (rightB > WIDTH)
	{
		ball->getVelocity().setX(-ballSpeed);
		Goal(0);
		return;
	}
	//player side
	if (leftB < 0)
	{
		ball->getVelocity().setX(ballSpeed);
		Goal(1);
		return;
	}
}

void PlayState::Goal(const uint8_t playerID)
{
	//playerID = 0, enemyID = 1
	!playerID ? playerScore->IncreaseScore() : enemyScore->IncreaseScore();
	//ball->resetPosition();
}

