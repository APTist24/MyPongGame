#ifndef _Player_
#define _Player_

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

#endif