#include "Enemy.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"

Enemy::Enemy(const LoaderParams* pParams) :
										GameObject(pParams)
{
}

void Enemy::draw() {
	GameObject::draw(); // we now use SDLGameObject
}

void Enemy::update() {
	acceleration.setY(0);
	velocity.setX(0);
	velocity.setY(0);

	handleInput();

	currentFrame = int(((SDL_GetTicks() / 100) % 1));

	GameObject::update();
}

void Enemy::clean() {
}

void Enemy::handleInput()
{
	//AI
}