#include "Game.h"
#include "SDL.h"
#include <SDL_ttf.h>
#include <iostream>

#include "InputHandler.h"
#include "MenuState.h"
#include <SDL_mixer.h>

Game* Game::instance = nullptr;

Game* Game::Instance()
{
	if (!instance)
		instance = new Game();
	return instance;
}

bool Game::init(const char* title, int width,
	int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cerr << "Unable to init SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	if (!Window) {
		std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
		return false;
	}

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!Renderer) {
		std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
		return false;
	}

	if (TTF_Init() == -1)
	{
		std::cerr << "Unable to init TTF: " << TTF_GetError() << std::endl;
	}

	Font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 35);
	if (!Font) {
		std::cerr << "Unable to open font: " << TTF_GetError() << std::endl;
	}

	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);

	isRunning = true; //main loop boolean, if false, stop game loop

	StateManager = new GameStateMachine();
	StateManager->changeState(new MenuState());

	return true;
}

void Game::render()
{
	SDL_RenderClear(Renderer); // clear the renderer to the draw color

	StateManager->render();

	SDL_RenderPresent(Renderer); // draw to the screen
}

void Game::update()
{
	StateManager->update();
}

void Game::handleEvents()
{
	InputHandler::Instance()->update();

}

void Game::clean()
{
	TTF_CloseFont(Font);
	TTF_Quit();
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}