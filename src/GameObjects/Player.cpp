#include "Player.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"

Player::Player(const LoaderParams* pParams) :
	GameObject(pParams)
{
}

void Player::draw() {
	GameObject::draw();
}

void Player::update() {
	acceleration.setY(0);
	velocity.setX(0);
	velocity.setY(0);

	handleInput();

	currentFrame = 0;

	GameObject::update();
}


void Player::handleInput()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		//collides check
		if (position.getY() > 0) {
			acceleration.setY(-5);
			velocity.setY(-10);
		}
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		if (position.getY() + height < HEIGHT)
		{
			acceleration.setY(5);
			velocity.setY(10);
		}
	}
}