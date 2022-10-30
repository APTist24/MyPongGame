#include "GameStateMachine.h"


void GameStateMachine::pushState(GameState* pState)
{
	vec_gameStates.push_back(pState);
	vec_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!vec_gameStates.empty())
	{
		if (vec_gameStates.back()->onExit())
		{
			delete vec_gameStates.back();
			vec_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if (!vec_gameStates.empty())
	{
		if (vec_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
	// push back our new state
	vec_gameStates.push_back(pState);
	// initialise it
	vec_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!vec_gameStates.empty())
	{
		vec_gameStates.back()->update();
	}
}
void GameStateMachine::render()
{
	if (!vec_gameStates.empty())
	{
		vec_gameStates.back()->render();
	}
}