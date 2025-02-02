#pragma once

#include <stack>
#include <States/GameState.h>
#include <memory>


class GameStateMachine
{
public:
	void pushState(std::unique_ptr<GameState>&& pState);
	void changeState(std::unique_ptr<GameState>&& pState);
	void popState();

	void update();
	void render();
private:
	std::stack<std::unique_ptr<GameState>> vec_gameStates;
};

