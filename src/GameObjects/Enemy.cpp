#include "Enemy.h"
#include <SDL.h>
#include "InputHandler.h"
#include "GameSettings.h"
#include "Ball.h"

Enemy::Enemy(const LoaderParams* pParams, GameObject* ball_) :
										GameObject(pParams), ball(ball_)
{
}

void Enemy::draw() {
	GameObject::draw();
}

void Enemy::update() {
	acceleration.setY(0);
	velocity.setX(0);
	velocity.setY(0);

	TryCatchBall();

	currentFrame = 0;

	GameObject::update();
}

void Enemy::TryCatchBall()
{
	auto ballPositionY = ball->getPosition().getY();
	auto ballPositionX = ball->getPosition().getX();
	auto objPositionY = position.getY();
	
	if (ballPositionX > WIDTH / 2)
	{
		if (ballPositionY < objPositionY)
		{
			//check wall collision
			if (position.getY() > 0) {
				acceleration.setY(-5);
				velocity.setY(-5);
			}
		}
		if (ballPositionY > objPositionY)
		{
			if (position.getY() + height < HEIGHT)
			{
				acceleration.setY(5);
				velocity.setY(5);
			}
		}
	}
}
