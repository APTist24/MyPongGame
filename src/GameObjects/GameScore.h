#ifndef __GameScore__
#define __GameScore__
#include "GameObject.h"
#include "SDL.h"

class GameScore : public GameObject
{
public:
	GameScore(const LoaderParams* pParams, SDL_Rect rect_);
	virtual void draw();
	virtual void update();
	virtual void clean() {};

	void IncreaseScore();

private:
	uint8_t score = 0;

	class SDL_Texture* scoreTexture;
	SDL_Rect rect;
};
#endif