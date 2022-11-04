#ifndef _Enemy_
#define _Enemy_

#include "GameObject.h"

class Enemy : public GameObject
{
public:

	Enemy(const LoaderParams* pParams, GameObject* ball_);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	class Ball* ball;
	void TryCatchBall();

};

#endif