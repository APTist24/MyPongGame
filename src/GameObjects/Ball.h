#pragma once

#include "GameOBject.h"
#include <functional>

class Ball : public GameObject
{
public:
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	auto getSpeed() { return speed; }
	void setSpeed(uint8_t val) { speed = val; }

	auto getSpeedLimit() { return maxBallSpeed; }

	void resetPosition(const uint8_t i = 0);

private:
	uint8_t speed;
	uint8_t startupSpeed = 5;
	uint8_t maxBallSpeed = 12;

};
