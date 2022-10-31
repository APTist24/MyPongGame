#include "Ball.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"


Ball::Ball(const LoaderParams* pParams) :
	GameObject(pParams)
{
	velocity.setX(BALL_SPEED);
	velocity.setY(BALL_SPEED);

}

void Ball::draw() {
	GameObject::draw(); // we now use SDLGameObject
}

void Ball::update() {

	CollisionCheck();

	currentFrame = int(((SDL_GetTicks() / 100) % 1));

	GameObject::update();
}

void Ball::clean() {
}

void Ball::CollisionCheck()
{
	//top
	if (position.getY() < 0)
	{
		velocity.setY(BALL_SPEED);
		return;
	}
	//bot
	if (position.getY() + BALL_SIZE > HEIGHT)
	{
		velocity.setY(-BALL_SPEED);
		return;
	}
	//ai side
	if (position.getX()  + BALL_SIZE > WIDTH)
	{
		velocity.setX(-BALL_SPEED);
		//goal, increment score
		return;
	}
	//player side
	if (position.getX()  < 0)
	{
		velocity.setX(BALL_SPEED);
		//goal, increment score
		return;
	}

}

//need reset function after goal