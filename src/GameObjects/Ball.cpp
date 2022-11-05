#include "Ball.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"
#include "PlayState.h"


Ball::Ball(const LoaderParams* pParams) :
	GameObject(pParams)
{
	resetPosition();
}

void Ball::draw() {
	GameObject::draw();
}

void Ball::update() {

	currentFrame = 0;

	GameObject::update();
}

void Ball::resetPosition()
{
	speed = startupSpeed;
	velocity.setX(speed);
	velocity.setY(speed);
	position.setX(HEIGHT / 2);
	position.setY(WIDTH / 2);
}