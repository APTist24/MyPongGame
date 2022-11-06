#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <stack>
#include "GameState.h"


class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	void update();
	void render();
private:
	std::stack<GameState*> vec_gameStates;
};

#endif