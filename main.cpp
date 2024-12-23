#include "SFML/Graphics.hpp"
#include "camera.hpp"
#include "input.hpp"
#include "map.hpp"
#include "renderer.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "BitMapper");
	ProgramState state;
	sf::Color bg(110, 110, 110);

	while (window.isOpen()) {
		// Event handling
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			handle_input(window, event, state);
		}

		window.clear(bg);

		render_map(window, state);
		draw_grid(window, state);

		window.display();
	}
}
