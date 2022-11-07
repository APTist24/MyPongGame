#include "GameOverState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "GameSettings.h"
#include "PlayState.h"
#include "MenuState.h"
#include "GameOverTexture.h"

const std::string GameOverState::gameOverID = "GAMEOVER";


GameOverState::GameOverState(uint8_t playerID_) : 
												GameState(),
												playerID(playerID_)
{

}

void GameOverState::update()
{
	for (auto obj : gameObjects)
		if (obj) obj->update();
}

void GameOverState::render()
{
	for (auto obj : gameObjects)
		if (obj) obj->draw();
}

bool GameOverState::onEnter()
{
	if (!TextureManager::Instance()->load("imgs/play_again.png",
		"playagain"))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(HEIGHT / 2, WIDTH / 2 - 50,
		135, 35, "playagain"), &onPlayPress);
	gameObjects.push_back(button1);

	GameObject* gameOverTextText = new GameOverTexture(new LoaderParams(playerID? (WIDTH / 4) : (WIDTH / 3), HEIGHT / 3, 0, 0, ""),
														"Game Over! " + playerID ? "Computer win, try again!" : "You win!");
	gameObjects.push_back(gameOverTextText);

	enterMus = Mix_LoadMUS("music/game_over.wav");
	if (!enterMus) std::cerr << "Can't load music" << std::endl;
	Mix_PlayMusic(enterMus, false);

	return true;
}

bool GameOverState::onExit()
{
	for (auto& obj : gameObjects)
		if (obj) obj->clean();

	gameObjects.clear();

	Mix_FreeMusic(enterMus);

	TextureManager::Instance()->clearFromTextureMap("playbutton");

	return true;
}

void GameOverState::onPlayPress()
{
	Game::Instance()->getStateMachine()->changeState(std::move(std::make_unique<PlayState>()));
}

