#include "Window.h"

Window::Window() { Setup("Window", sf::Vector2u(640, 480)); }
Window::Window(const std::string& l_title,
	const sf::Vector2u& l_size)
{
	Setup(l_title, l_size);
}
Window::~Window() { Destroy(); }

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}
void Window::Create() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen
		: sf::Style::Default);
	this->create({ m_windowSize.x, m_windowSize.y, 32 },
		m_windowTitle, style);
}
void Window::Destroy() {
	this->close();
}
void Window::Update(sf::Event& event) {
		if (event.type == sf::Event::Closed) {
			Destroy();
		}
		else if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
}
void Window::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}


void Window::BeginDraw() { this->clear(sf::Color::Black); }
void Window::EndDraw() { this->display(); }

bool Window::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

//-----------------------------------------------------------------------//
//--------------------- setting scaled background ----------------------//
//---------------------------------------------------------------------//
void Window::setBackground(const std::string& path)
{

	m_sprite = Resources::instance().get_img(path);
	m_sprite.setPosition(sf::Vector2f(0, 0));
	m_sprite.scale(m_windowSize.x / m_sprite.getGlobalBounds().width,
		m_windowSize.y / m_sprite.getGlobalBounds().height);

	*this << m_sprite;

}
//-----------------------------------------------------------------------//
//-------------------- operator to draw sprites ------------------------//
//---------------------------------------------------------------------//
Window& operator<<(Window& window, const sf::Sprite& sprite)
{
	window.draw(sprite);
	return window;
}