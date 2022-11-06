#ifndef __GameOverTexture__
#define __GameOverTexture__

#include "GameObject.h"
#include "SDL.h"

class GameOverTexture : public GameObject
{
public:
	GameOverTexture(const LoaderParams* pParams, const std::string& text);

	virtual void draw();
	virtual void clean() { SDL_DestroyTexture(sdlTexture); }
private:
	struct SDL_Texture* sdlTexture;
	SDL_Rect rect;
};


#endif