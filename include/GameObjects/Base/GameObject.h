#pragma once

#include "IGameObject.h"
#include <string>
#include "Vector2D.h"


class GameObject : public IGameObject
{
public:
	GameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	Vector2D& getPosition() { return position; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	Vector2D& getVelocity() { return velocity; }

protected:
	Vector2D position;
	int width;
	int height;
	int currentRow;
	int currentFrame;
	std::string textureID;

	Vector2D velocity;
	Vector2D acceleration;
};
