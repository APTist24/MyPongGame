#pragma once

#include "GameObject.h"
#include "SDL.h"

class ScoreText : public GameObject
{
public:
	ScoreText(const LoaderParams* pParams, const std::string& text);

	virtual void update() {};
	virtual void draw();
	virtual void clean() { SDL_DestroyTexture(sdlTexture); }
private:
	struct SDL_Texture* sdlTexture;
	SDL_Rect rect;
};
