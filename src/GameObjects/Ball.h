#ifndef __Ball__
#define __Ball__

#include "GameObject.h"


class Ball : public GameObject
{
public:
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void CollisionCheck();

};
#endif