#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(const LoaderParams* pParams,
						std::function<void()> call_b) :
														GameObject(pParams),
														callback(call_b)
{
	currentFrame = MOUSE_OUT; 
}

void MenuButton::draw()
{
	GameObject::draw();
}

void MenuButton::update()
{
	Vector2D* pMousePos = InputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (position.getX() + width)
		&& pMousePos->getX() > position.getX()
		&& pMousePos->getY() < (position.getY() + height)
		&& pMousePos->getY() > position.getY())
	{
		currentFrame = MOUSE_OVER;
		if (InputHandler::Instance()->getMouseButtonState(LEFT)  && isReleased)
		{
			currentFrame = CLICKED;
			callback(); 
			isReleased = false;
		}
		else if (!InputHandler::Instance()->getMouseButtonState(LEFT))
		{
			isReleased = true;
			currentFrame = MOUSE_OVER;
		}
	}
	else
	{
		currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	GameObject::clean();
}