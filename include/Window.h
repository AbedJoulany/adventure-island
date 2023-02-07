#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"
class Window : public sf::RenderWindow {
public:
	Window();
	Window(const std::string& l_title, const sf::Vector2u& l_size);
	~Window();
	void BeginDraw(); // Clear the window.
	void EndDraw(); // Display the changes.
	void Update(sf::Event &event);
	bool IsFullscreen();
	sf::Vector2u GetWindowSize();
	void ToggleFullscreen();
	//void draw(const sf::Drawable& drawable);
	// setting the background
	void setBackground(const std::string& path);
private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
	sf::Sprite m_sprite;

};
Window& operator<<(Window& window, const sf::Sprite& sprite);
