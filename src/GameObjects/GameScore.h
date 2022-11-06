#ifndef __GameScore__
#define __GameScore__
#include "GameObject.h"
#include "SDL.h"

class GameScore : public GameObject
{
public:
	GameScore(const LoaderParams* pParams);
	virtual void draw();
	virtual void clean() {};

	void IncreaseScore(const uint8_t playerID = 0);

private:
	uint8_t score = 0;

	struct SDL_Texture* scoreTexture;
	SDL_Rect rect;
};
#endif