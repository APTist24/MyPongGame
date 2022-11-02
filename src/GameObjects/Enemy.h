#ifndef _Enemy_
#define _Enemy_

#include "GameObject.h"

class Enemy : public GameObject
{
public:

	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	void handleInput();
};

#endif