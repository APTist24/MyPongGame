#include "Ball.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"

Ball::Ball(const LoaderParams* pParams) :
	GameObject(pParams)
{
	velocity.setX(5);
	velocity.setY(5);

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
	if (position.getY() < 1)
	{
		//velocity.setX(-5);
		velocity.setY(5);
	}
	if (position.getY() + 15 > HEIGHT)
	{
		velocity.getX();
		velocity.setY(-5);
	}
	if (position.getX() + 25 > WIDTH)
	{
		velocity.setX(-5);
	}
	if (position.getX() - 25 < 0)
	{
		velocity.setX(5);
	}

}