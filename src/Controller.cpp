#include "Controller.h"

Controller::Controller()
	:m_window("island", sf::Vector2u(800, 600)),
	m_game(m_window)
{
	m_state = GameState::inMenu;
}

Controller::~Controller()
{
}

void Controller::run()
{

	while (m_window.isOpen())
	{
		switch (m_state)
		{
		case GameState::inMenu:
			renderMenu();
			break;
		case GameState::inGame:
			renderGame();
			break;
		}
	}
}

void Controller::renderGame()
{
	m_window.BeginDraw();
	m_game.Update(m_window, m_state);
	m_game.Render(m_window);
	//m_window.setBackground("grass.jpg");
	m_window.EndDraw();
}

void Controller::renderMenu()
{
	m_window.BeginDraw();
	m_menu.update(m_window, m_state);
	m_menu.Render(m_window);
	m_window.EndDraw();
}
