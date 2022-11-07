#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:

	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	void handleInput();
};
