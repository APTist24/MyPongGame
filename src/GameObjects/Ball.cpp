// #include "Ball.h"
// #include <SDL.h>
// #include "InputHandler.h"
// #include "GameSettings.h"
// #include "PlayState.h"
//
//
// Ball::Ball(const LoaderParams* pParams) :
// 	GameObject(pParams)
// {
// 	resetPosition();
// }
//
// void Ball::draw() {
// 	GameObject::draw();
// }
//
// void Ball::update() {
//
// 	currentFrame = 0;
//
// 	GameObject::update();
// }
//
// void Ball::resetPosition(const uint8_t i)
// {
// 	speed = startupSpeed;
// 	//if
// 	if (i) {
// 		velocity.setX(speed);
// 		velocity.setY(speed);
// 	}
// 	else {
// 		velocity.setX(-speed);
// 		velocity.setY(-speed);
// 	}
// 	position.setX(WIDTH / 2);
// 	position.setY(HEIGHT / 2);
// }