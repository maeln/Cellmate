#include <iostream>

#include <SFML/Graphics.hpp>

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
	sf::Font font;
	if(!font.loadFromFile("data/fonts/ubuntu/ubuntumono.ttf"))
		return -1;
	sf::Text text("Hello World !", font, 48);
	text.setPosition(window.getSize().x / 2.0, window.getSize().y / 2.0);
	text.setColor(sf::Color(64, 255, 128));
	
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color(255, 255, 255));
		window.draw(text);
		window.display();
	}
	
	return 0;
}

