#include "renderer.hpp"

const float MIN_ZOOM_FOR_GRID = 0.5f;

void render_map(sf::RenderWindow& w, ProgramState& s) {
	for (auto& l : s.map.layers) {
	}
}

void draw_grid(sf::RenderWindow& w, ProgramState& s) {
	if (s.cam.zoomf < MIN_ZOOM_FOR_GRID) return;

	int grid_width = w.getSize().x;
	int grid_height = w.getSize().y;
	int cell_size = 20 * s.cam.zoomf;

	sf::VertexArray grid_lines(sf::Lines);

	for (int x = s.cam.offset.x % cell_size; x <= grid_width; x += cell_size) {
		grid_lines.append(sf::Vertex(sf::Vector2f(x, 0), sf::Color::White));
		grid_lines.append(sf::Vertex(sf::Vector2f(x, grid_height), sf::Color::White));
	}

	for (int y = s.cam.offset.y % cell_size; y <= grid_height; y += cell_size) {
		grid_lines.append(sf::Vertex(sf::Vector2f(0, y), sf::Color::White));
		grid_lines.append(sf::Vertex(sf::Vector2f(grid_width, y), sf::Color::White));
	}

	w.draw(grid_lines);
}
