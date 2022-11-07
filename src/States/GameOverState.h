#pragma once

#include "GameState.h"
#include <vector>
#include <SDL_mixer.h>

class GameOverState : public GameState
{
public:
	GameOverState(uint8_t playerID_);
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return gameOverID; }

private:

	static void onPlayPress();

	static const std::string gameOverID;
	std::vector<class GameObject*> gameObjects;
	uint8_t playerID;

	Mix_Music* enterMus;



};

