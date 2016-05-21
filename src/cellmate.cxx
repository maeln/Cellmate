#include <iostream>

#include <SFML/Graphics.hpp>
#include "World.hxx"
#include "WorldRenderer.hxx"

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
	World world(8, 6, 0);
	WorldRenderer w_renderer(&world, &window);

	world.set_cell_state_at(0, 0, 1);
	world.set_cell_state_at(7, 5, 1);
	world.set_cell_state_at(4, 3, 1);
	world.set_cell_state_at(7, 0, 1);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color(255, 255, 255));

		w_renderer.render_world();

		window.display();
	}
	
	return 0;
}

