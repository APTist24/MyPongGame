#pragma once

#include "GameObject.h"
#include "SDL.h"

class GameScore : public GameObject
{
public:
	GameScore(const LoaderParams* pParams);
	virtual void draw();
	virtual void clean() { SDL_DestroyTexture(scoreTexture); };

	void IncreaseScore(const uint8_t playerID = 0);

private:
	uint8_t score = 0;

	struct SDL_Texture* scoreTexture;
	SDL_Rect rect;
};
