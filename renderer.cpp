#include "renderer.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

const int MIN_CELL_SIZE = 10;
const int CELL_SIZE = 20;
const int CHUNK_SIZE = 8;
const sf::Color GRID_COLOR = sf::Color(195, 195, 195);
const sf::Color GRID_CENTER_COLOR = sf::Color(255, 125, 125);
const sf::Color GRID_CHUNK_COLOR = sf::Color(125, 156, 255);
const sf::Color GRID_LARGE_CHUNK_COLOR = sf::Color(125, 255, 130);

void render_map(sf::RenderWindow& w, ProgramState& s) {
	for (auto& l : s.map.layers) {
	}
}

// Draws the grid.
void draw_grid(sf::RenderWindow& w, ProgramState& s) {
	int grid_width = w.getSize().x;
	int grid_height = w.getSize().y;
	int cell_size = CELL_SIZE * s.cam.zoomf;
	int chunk_size;
	int large_chunk_size;

	sf::VertexArray grid_lines(sf::Lines);

	// Draw small grid.
	if (cell_size >= MIN_CELL_SIZE) {
		for (int x = s.cam.offset.x % cell_size; x <= grid_width; x += cell_size) {
			grid_lines.append(sf::Vertex(sf::Vector2f(x, 0), GRID_COLOR));
			grid_lines.append(sf::Vertex(sf::Vector2f(x, grid_height), GRID_COLOR));
		}

		for (int y = s.cam.offset.y % cell_size; y <= grid_height; y += cell_size) {
			grid_lines.append(sf::Vertex(sf::Vector2f(0, y), GRID_COLOR));
			grid_lines.append(sf::Vertex(sf::Vector2f(grid_width, y), GRID_COLOR));
		}

		chunk_size = cell_size * CHUNK_SIZE;
	} else {
		chunk_size = CELL_SIZE * CHUNK_SIZE * s.cam.zoomf;
	}

	if (chunk_size >= MIN_CELL_SIZE) {
		// Draw chunk grid.
		for (int x = s.cam.offset.x % chunk_size; x <= grid_width; x += chunk_size) {
			grid_lines.append(sf::Vertex(sf::Vector2f(x, 0), GRID_CHUNK_COLOR));
			grid_lines.append(sf::Vertex(sf::Vector2f(x, grid_height), GRID_CHUNK_COLOR));
		}

		for (int y = s.cam.offset.y % chunk_size; y <= grid_height; y += chunk_size) {
			grid_lines.append(sf::Vertex(sf::Vector2f(0, y), GRID_CHUNK_COLOR));
			grid_lines.append(sf::Vertex(sf::Vector2f(grid_width, y), GRID_CHUNK_COLOR));
		}

		large_chunk_size = chunk_size * CHUNK_SIZE;
	} else {
		large_chunk_size = CHUNK_SIZE * CHUNK_SIZE * CELL_SIZE * s.cam.zoomf;
	}

	if (large_chunk_size >= MIN_CELL_SIZE) {
		// Draw large chunk grid.
		for (int x = s.cam.offset.x % large_chunk_size; x <= grid_width; x += large_chunk_size) {
			grid_lines.append(sf::Vertex(sf::Vector2f(x, 0), GRID_LARGE_CHUNK_COLOR));
			grid_lines.append(sf::Vertex(sf::Vector2f(x, grid_height), GRID_LARGE_CHUNK_COLOR));
		}

		for (int y = s.cam.offset.y % large_chunk_size; y <= grid_height; y += large_chunk_size) {
			grid_lines.append(sf::Vertex(sf::Vector2f(0, y), GRID_LARGE_CHUNK_COLOR));
			grid_lines.append(sf::Vertex(sf::Vector2f(grid_width, y), GRID_LARGE_CHUNK_COLOR));
		}
	}

	// Draw the center of the map in red lines.
	grid_lines.append(sf::Vertex(sf::Vector2f(s.cam.offset.x, 0), GRID_CENTER_COLOR));
	grid_lines.append(sf::Vertex(sf::Vector2f(s.cam.offset.x, grid_height), GRID_CENTER_COLOR));

	grid_lines.append(sf::Vertex(sf::Vector2f(0, s.cam.offset.y), GRID_CENTER_COLOR));
	grid_lines.append(sf::Vertex(sf::Vector2f(grid_width, s.cam.offset.y), GRID_CENTER_COLOR));

	w.draw(grid_lines);
}
