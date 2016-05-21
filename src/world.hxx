/**
 * Define the world in which the cells evolve.
 */

#include <vector>

class Cell
{
public:
	Cell() {};
	Cell(int s) {state = s;};
	int state;
};

class World
{
public:
	World();
	World(unsigned int width, unsigned int height, int default_state = 0);
	~World();

	// Properties getter
	unsigned int get_width();
	unsigned int get_height();

	// Cell getter/setter
	Cell get_cell_at(unsigned int x, unsigned int y);
	void set_cell_state_at(unsigned int x, unsigned int y, int state);
	
private:
	unsigned int m_width;
	unsigned int m_height;
	std::vector<Cell> m_space;
};

