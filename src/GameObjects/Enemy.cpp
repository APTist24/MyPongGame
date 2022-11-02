#include "Enemy.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"

Enemy::Enemy(const LoaderParams* pParams) :
										GameObject(pParams)
{
}

void Enemy::draw() {
	GameObject::draw();
}

void Enemy::update() {

	velocity.setX(0);
	velocity.setY(0);

	handleInput();

	currentFrame = 0;

	GameObject::update();
}

void Enemy::handleInput()
{
	//AI
}