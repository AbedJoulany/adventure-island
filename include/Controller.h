#pragma once
#include "GameState.h"
#include "Game.h"
#include "Menu.h"

class Controller {

public:

	Controller();
	~Controller();

	void run();
	void renderGame();
	// render the menu
	void renderMenu();

private:
	Window m_window;
	GameState m_state;
	Game m_game; // Creating our game object.
	Menu m_menu;

};