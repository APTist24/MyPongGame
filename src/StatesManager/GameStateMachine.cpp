#include "GameStateMachine.h"


void GameStateMachine::pushState(GameState* pState)
{
	vec_gameStates.push(pState);
	vec_gameStates.top()->onEnter();
}

void GameStateMachine::popState()
{
	if (!vec_gameStates.empty())
	{
		if (vec_gameStates.top()->onExit())
		{
			delete vec_gameStates.top();
			vec_gameStates.pop();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if (!vec_gameStates.empty())
	{
		if (vec_gameStates.top()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
		if (vec_gameStates.top()->onExit())
		{
			delete vec_gameStates.top();
			vec_gameStates.pop();
		}
	}
	vec_gameStates.push(pState);
	vec_gameStates.top()->onEnter();
}

void GameStateMachine::update()
{
	if (!vec_gameStates.empty())
	{
		vec_gameStates.top()->update();
	}
}
void GameStateMachine::render()
{
	if (!vec_gameStates.empty())
	{
		vec_gameStates.top()->render();
	}
}