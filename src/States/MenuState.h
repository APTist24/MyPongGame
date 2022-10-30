#ifndef __MenuState__
#define __MenuState__

#include "GameState.h"
#include <vector>

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return menuID; }

private:
	static const std::string menuID;

	std::vector<class GameObject*> gameObjects;

	static void onPlayPress();
	static void onQuitPress();

};

#endif