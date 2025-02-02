// #include "PlayState.h"
// #include "GameObject.h"
// #include "TextureManager.h"
// #include "InputHandler.h"
// #include "PauseState.h"
// #include "Player.h"
// #include "Enemy.h"
// #include "Ball.h"
// #include "GameScore.h"
// #include "GameSettings.h"
// #include "ScoreText.h"
//
// const std::string PlayState::playID = "PLAY";
//
// void PlayState::update()
// {
// 	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
// 	{
// 		Game::Instance()->getStateMachine()->pushState(std::move(std::make_unique<PauseState>()));
// 	}
//
// 	for (auto obj: gameObjects)
// 		if(obj) obj->update();
//
// 	auto ballPtr = static_cast<Ball*>(ball);
//
// 	if (checkCollision(enemy)) {
// 		Mix_PlayMusic(rocketMus, false);
// 		auto ballSpeed = ballPtr->getSpeed();
// 		auto maxBallSpeed = ballPtr->getSpeedLimit();
// 		ballPtr->getVelocity().setX(-ballSpeed);
// 		if (ballSpeed < maxBallSpeed)
// 			ballPtr->setSpeed(++ballSpeed);
// 	}
// 	if (checkCollision(player)) {
// 		Mix_PlayMusic(rocketMus, false);
// 		auto ballSpeed = ballPtr->getSpeed();
// 		auto maxBallSpeed = ballPtr->getSpeedLimit();
// 		ballPtr->getVelocity().setX(ballSpeed);
// 		if (ballSpeed < maxBallSpeed)
// 			ballPtr->setSpeed(++ballSpeed);
// 	}
//
// 	checkWallCollision();
//
// }
//
// void PlayState::render()
// {
// 	for (auto obj : gameObjects)
// 		if(obj) obj->draw();
// 	//draw central line
// 	
// }
// bool PlayState::onEnter()
// {
// 	if (!TextureManager::Instance()->load("imgs/player.png",
// 		"player"))
// 	{
// 		return false;
// 	}
//
// 	if (!TextureManager::Instance()->load("imgs/ball.png",
// 		"ball"))
// 	{
// 		return false;
// 	}
//
// 	player = new Player(new LoaderParams(0, 100, 25, 150, "player"));
// 	gameObjects.push_back(player);
//
// 	ball = new Ball(new LoaderParams(WIDTH / 2, HEIGHT / 2, 25, 25, "ball"));
// 	gameObjects.push_back(ball);
//
// 	enemy = new Enemy(new LoaderParams(WIDTH - 25, 100, 25, 150, "player"), ball);
// 	gameObjects.push_back(enemy);
//
// 	auto scoreText = new ScoreText(new LoaderParams((WIDTH / 2) - 50, 5, 0, 0, ""), "Score :");
// 	gameObjects.push_back(scoreText);
//
// 	playerScore = new GameScore(new LoaderParams((WIDTH / 2) - 50, 50, 0, 0, ""));
// 	gameObjects.push_back(playerScore);
//
// 	enemyScore = new GameScore(new LoaderParams((WIDTH / 2) + 50, 50, 0, 0, ""));
// 	gameObjects.push_back(enemyScore);
//
// 	goalMus = Mix_LoadMUS("music/goal.wav");
// 	if (!goalMus) std::cerr << "Can't load music" << std::endl;
//
// 	rocketMus = Mix_LoadMUS("music/rocket_sound.wav");
// 	if (!rocketMus) std::cerr << "Can't load music" << std::endl;
//
//
// 	return true;
// }
//
//
// bool PlayState::onExit()
// {
// 	for (auto obj : gameObjects)
// 		if(obj) obj->clean();
//
// 	gameObjects.clear();
//
// 	Mix_FreeMusic(goalMus);
// 	Mix_FreeMusic(rocketMus);
//
// 	return true;
// }
//
// bool PlayState::checkCollision(GameObject* obj)
// {
// 	int leftA, leftB;
// 	int rightA, rightB;
// 	int topA, topB;
// 	int bottomA, bottomB;
//
// 	leftA = obj->getPosition().getX();
// 	rightA = obj->getPosition().getX() + obj->getWidth();
// 	topA = obj->getPosition().getY();
// 	bottomA = obj->getPosition().getY() + obj->getHeight();
//
// 	//Calculate the sides of rect Ball
// 	leftB = ball->getPosition().getX();
// 	rightB = ball->getPosition().getX() + ball->getWidth();
// 	topB = ball->getPosition().getY();
// 	bottomB = ball->getPosition().getY() + ball->getHeight();
//
// 	//If any of the sides from A are outside of Ball
// 	if (bottomA <= topB) 
// 		return false; 
// 	if (topA >= bottomB) 
// 		return false;
// 	if (rightA <= leftB) 
// 		return false;
// 	if (leftA >= rightB)  
// 		return false; 
//
// 	return true;
// }
//
// void PlayState::checkWallCollision()
// {
// 	int leftB = ball->getPosition().getX();
// 	int rightB = ball->getPosition().getX() + ball->getWidth();
// 	int topB = ball->getPosition().getY();
// 	int bottomB = ball->getPosition().getY() + ball->getHeight();
//
// 	auto ball_ = static_cast<Ball*>(ball);
// 	auto ballSpeed = ball_->getSpeed();
// 	//top
// 	if (topB < 0)
// 	{
// 		ball_->getVelocity().setY(ballSpeed);
// 		return;
// 	}
// 	//bot
// 	if (bottomB > HEIGHT)
// 	{
// 		ball_->getVelocity().setY(-ballSpeed);
// 		return;
// 	}
// 	//ai side
// 	if (rightB > WIDTH)
// 	{
// 		ball_->getVelocity().setX(-ballSpeed);
// 		Mix_PlayMusic(goalMus, false);
// 		Goal(0);
// 		return;
// 	}
// 	//player side
// 	if (leftB < 0)
// 	{
// 		ball_->getVelocity().setX(ballSpeed);
// 		Mix_PlayMusic(goalMus, false);
// 		Goal(1);
// 		return;
// 	}
// }
//
// void PlayState::Goal(const uint8_t playerID)
// {
// 	static_cast<Ball*>(ball)->resetPosition(playerID);
// 	//playerID = 0, enemyID = 1
// 	!playerID ? playerScore->IncreaseScore(0) : enemyScore->IncreaseScore(1);
// }
//
