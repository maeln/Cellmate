//
// Created by maeln on 21/05/16.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "WorldRenderer.hxx"

WorldRenderer::WorldRenderer()
{
	m_world = NULL;
	m_window = NULL;
}

WorldRenderer::WorldRenderer(World *world, sf::RenderWindow *window)
{
	m_world = world;
	m_window = window;
}

sf::Vector2f WorldRenderer::cell_view_size()
{
	float cell_width = m_window->getSize().x / m_world->get_width();
	float cell_height = m_window->getSize().y / m_world->get_height();

	return sf::Vector2f(cell_width, cell_height);
}

void WorldRenderer::render_world()
{
	sf::Vector2f cell_size = cell_view_size();

	for(unsigned int y = 0; y<m_world->get_height(); ++y)
	{
		for(unsigned int x = 0; x<m_world->get_width(); ++x)
		{
			// TODO: Create a coloration method for cell depending on their state.
			if(m_world->get_cell_at(x, y).state > 0)
			{
				sf::RectangleShape rect(cell_size);
				rect.setPosition(float(x) * cell_size.x, float(y) * cell_size.y);
				rect.setFillColor(sf::Color(0,0,0));
				m_window->draw(rect);
			}
		}
	}

}







