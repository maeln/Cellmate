#include "world.hxx"

World::World()
{
	m_width = 0;
	m_height = 0;
	m_space = std::vector<Cell>();
}

World::World(unsigned int width, unsigned int height, int default_state = 0)
{
	m_width = width;
	m_height = height;
	m_space = std::vector<Cell>(width*height, Cell(default_state));
}

World::~World()
{
	m_space.clear();
}

Cell World::get_cell_at(unsigned int x, unsigned int y)
{
	return m_space[x+y*m_width];
}

void World::set_cell_state_at(unsigned int x, unsigned int y, int state)
{
	m_space[x+y*m_width].state = state;
}

unsigned int World::get_width()
{
	return m_width;
}

unsigned int World::get_height()
{
	return m_height;
}













