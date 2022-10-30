#include "Game.h"
#include "SDL.h"
#include <iostream>

#include "InputHandler.h"
#include "MenuState.h"

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

	// initialize the SDL2 framework along with systems.
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	// try to create a new window for the application.
	Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	if (!Window) {
		std::cerr << "Unable to create SDL window: " << SDL_GetError() << std::endl;
		return false;
	}

	// try to create a new renderer for the application window.
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!Renderer) {
		std::cerr << "Unable to create SDL renderer: " << SDL_GetError() << std::endl;
		return false;
	}

	isRunning = true; // everything inited successfully, start the main loop

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
	SDL_DestroyWindow(Window);
	SDL_DestroyRenderer(Renderer);
	SDL_Quit();
}