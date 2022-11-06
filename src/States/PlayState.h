#ifndef __PlayState__
#define __PlayState__

#include "GameState.h"
#include <vector>
#include <memory>

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	void Goal(const uint8_t playerID);

	virtual std::string getStateID() const { return playID; }

private:
	static const std::string playID;
	std::vector<class GameObject*> gameObjects;

	class GameObject* player;
	class GameObject* enemy;
	class GameObject* ball;
	class GameScore* playerScore;
	class GameScore* enemyScore;

	bool checkCollision(class GameObject* obj);
	bool checkWallCollision();

};

#endif
