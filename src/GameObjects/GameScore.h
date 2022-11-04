#ifndef __GameScore__
#define __GameScore__
#include "GameObject.h"

class GameScore : public GameObject
{
public:
	GameScore(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void IncreaseScore();

private:
	uint8_t score = 0;
};
#endif