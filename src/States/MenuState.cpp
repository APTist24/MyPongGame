#include "MenuState.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{

}

void MenuState::render()
{

}

bool MenuState::onEnter()
{
	return true;
}

bool MenuState::onExit()
{
	return true;
}

void MenuState::onPlayPress()
{

}

void MenuState::onQuitPress()
{
	Game::Instance()->quit();
}

