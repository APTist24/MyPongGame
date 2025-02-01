#pragma once

#include "GameObject.h"
#include <functional>

class MenuButton : public GameObject
{
public:
	MenuButton(const LoaderParams* pParams, std::function<void()> call_b);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	std::function<void()> callback;

	bool isReleased;
};
