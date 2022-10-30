#ifndef __GameOverState__
#define __GameOverState__

#include "GameState.h"
#include <vector>

class GameOverState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_gameOverID; }

private:

	static void gameOverToMain();
	static void restartPlay();
	static const std::string s_gameOverID;
	std::vector<class GameObject*> m_gameObjects;

};

#endif