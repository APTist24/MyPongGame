#ifndef __PauseState__
#define __PauseState__

#include "GameState.h"
#include <vector>

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return pauseID; }

private:

	static void onMainMenuClick();
	static void onResumeClick();
	static const std::string pauseID;
	std::vector<class GameObject*> gameObjects;
};
#endif