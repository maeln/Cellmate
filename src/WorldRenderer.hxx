//
// Created by maeln on 21/05/16.
//

#ifndef CELLMATE_WORLDRENDERER_HXX
#define CELLMATE_WORLDRENDERER_HXX


#include <SFML/Graphics/RenderWindow.hpp>
#include "World.hxx"

class WorldRenderer
{
public:
	WorldRenderer();
	WorldRenderer(World *world, sf::RenderWindow *window);

	void render_world();

private:
	World *m_world;
	sf::RenderWindow *m_window;

	// Resolved cell's view size.
	sf::Vector2f cell_view_size();
};


#endif //CELLMATE_WORLDRENDERER_HXX
