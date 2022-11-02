#ifndef __Ball__
#define __Ball__

#include "GameObject.h"
#include <functional>

#define BALL_SIZE 15 //rect size
#define BALL_SPEED 7 //ball speed settings, temporary here

class Ball : public GameObject
{
public:
	Ball(const LoaderParams* pParams, class PlayState* ps);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

private:
	void CollisionCheck();
	class PlayState* playState;

};
#endif