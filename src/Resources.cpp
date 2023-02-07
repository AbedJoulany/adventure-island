#include "Resources.h"
#include "Window.h"

//--------------- singleton ---------------------------------------------------
Resources& Resources::instance()
{
	static Resources resource;

	return resource;
}
//-------------------- get image ----------------------------------------------
sf::Sprite Resources::get_img(const std::string& path)
{
	sf::Sprite mSprite;
	if (textures.find(path) == textures.end())
	{
		textures[path] = std::make_unique<sf::Texture>();
		textures[path]->loadFromFile(path);
		textures[path]->setSmooth(true);
	}
	mSprite.setTexture(*textures[path]);

	return mSprite;
}
//------------------- get icon ------------------------------------------------
const sf::Uint8* Resources::get_icon(const std::string& path)
{
	static sf::Image window_icon;

	window_icon.loadFromFile(path);

	return (window_icon.getPixelsPtr());
}
//------------------- get font ------------------------------------------------
const sf::Font& Resources::get_font(const std::string& path)
{
	font.loadFromFile(path);

	return font;
}
//------------------- get sound ------------------------------------------------
sf::Sound* Resources::getSound(const std::string& path)
{
	if (sounds.find(path) == sounds.end())
	{
		sounds[path] = std::make_unique<sf::Sound>();
		sounds[path]->setBuffer(*this->getBuffer(path));
	}
	return sounds[path].get();
}
//-------------------- get buffer ---------------------------------------------
sf::SoundBuffer* Resources::getBuffer(const std::string& path)
{
	if (sound_buffers.find(path) == sound_buffers.end())
	{
		sound_buffers[path] = std::make_unique<sf::SoundBuffer>();
		sound_buffers[path]->loadFromFile(path);
	}
	return sound_buffers[path].get();
}
//------------------- gets music ----------------------------------------------
sf::Music& Resources::getMusic(const std::string& path)
{
	music.openFromFile(path);
	// Change some parameters
	music.setPosition(0, 1, 10); // change its 3D position
	music.setVolume(50);         // reduce the volume
	music.setLoop(true);         // make it loop

	return music;
}
//------------------ gets text ------------------------------------------------
sf::Text Resources::getTxt(const std::string& str,
	const int& positionX, const int& positionY,
	const std::string& fontPath,
	const bool& centerize, const sf::Color& color,
	const int& size, const float& thickness)
{
	sf::Text my_text;

	my_text.setFont(this->get_font(fontPath));
	my_text.setString(str);

	my_text.setCharacterSize(size);
	if (centerize) {
		sf::FloatRect textRect = my_text.getLocalBounds();
		my_text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
	}

	my_text.setOutlineThickness(thickness);//thickness of the font


	my_text.setPosition(positionX, positionY);//position
	my_text.setColor(color);//color

	return (my_text);
}
//-- non needed constructor but useful to be private implemented for singleton-
Resources::Resources()
{}
//----------------------- empty destructor ------------------------------------
Resources::~Resources() {}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

