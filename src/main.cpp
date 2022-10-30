#include "SDL.h"
#include <iostream>
#include "Game/Game.h"
#include "Game/GameSettings.h"


int main(int argc, char* argv[])
{
	size_t frameStart, frameTime;

	if (Game::Instance()->init("PongGame", WIDTH, HEIGHT,
		false))
	{
		while (Game::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cerr << "Can't Initialize Game : " << "\n" << SDL_GetError() << "\n";
		return -1;
	}

	Game::Instance()->clean();
	return 0;

}