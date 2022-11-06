#ifndef _Enemy_
#define _Enemy_

#include "GameObject.h"
#include <memory>

class Enemy : public GameObject
{
public:

	Enemy(const LoaderParams* pParams, class GameObject* ball_);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	class GameObject* ball;
	void TryCatchBall();

};

#endif