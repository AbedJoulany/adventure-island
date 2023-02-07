#pragma once
#include "Window.h"
#include <functional>
#include <string>
#include "GameState.h"

enum MenuOptions {
	Play,
	NewGame,
	Quit,
};

using std::string;

class Menu {
public:

	// constructor
	Menu();
	// destructor
	~Menu();
	// function to run the menu.
	void update(Window& window, GameState& state);
	// function to handle the key events
	void handleKeys(const sf::Event::KeyEvent& keyEvent);
	// function to handle to handle menu options
	void handleOption(Window& window, GameState& state);
	// function to clear and display on screen
	void Render(Window& window);
	// function to draw objects on screen.
	void drawOnScreen(Window& window);
	// funcgtion to run the game
	void play(GameState& state);
	// function to play and stop music
	void NewGame(GameState& state);
	// function to quit the game
	void quit(Window& window, GameState& state);

private:
	std::vector<string> m_options;
	int m_selectedOption;
};