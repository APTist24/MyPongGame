#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include <vector>

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	bool checkCollision(class GameObject* obj);

	virtual std::string getStateID() const { return playID; }

private:
	static const std::string playID;
	std::vector<class GameObject*> gameObjects;

	class GameObject* player;
	class GameObject* enemy;
	class GameObject* ball;
	class GameScore* playerScore;
	class GameScore* enemyScore;

	void Goal(const uint8_t playerID);
};

#endif
