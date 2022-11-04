#include "Ball.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"
#include "PlayState.h"


Ball::Ball(const LoaderParams* pParams) :
	GameObject(pParams)
{
	velocity.setX(speed);
	velocity.setY(speed);

}

void Ball::draw() {
	GameObject::draw();
}

void Ball::update() {

	currentFrame = 0;

	GameObject::update();
}


//need reset function after goal