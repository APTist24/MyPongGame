#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <vector>

class GameStateMachine
{
public:
	void pushState(class GameState* pState);
	void changeState(class GameState* pState);
	void popState();

	void update();
	void render();
private:
	std::vector<class GameState*> vec_gameStates;
};

#endif