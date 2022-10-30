#include "Player.h"
#include <SDL.h>
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) :
	GameObject(pParams)
{
}

void Player::draw() {
	GameObject::draw(); // we now use SDLGameObject
}

void Player::update() {
	velocity.setX(0);
	velocity.setY(0);

	handleInput();

	currentFrame = int(((SDL_GetTicks() / 100) % 4));
	/***MOVE IMAGE TO MOUSE*/
	//Vector2D* vec = InputHandler::Instance()->getMousePosition();
	//m_velocity = (*vec - m_position) / 10;
	/**********************/
	GameObject::update();
}

void Player::clean() {
}

void Player::handleInput()
{
	//if (InputHandler::Instance()->getMouseButtonState(LEFT))
	//{
	//	m_velocity.setX(1);
	//}
	//if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	//{
	//	m_velocity.setX(2);
	//}
	//if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	//{
	//	m_velocity.setX(-2);
	//}
	//if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	//{
	//	m_velocity.setY(-2);
	//}
	//if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	//{
	//	m_velocity.setY(2);
	//}
}