#include "input.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "program_state.hpp"

const float ZOOM_MULT = 0.2f;

static void handle_dragging(sf::RenderWindow& w, sf::Event& e, ProgramState& s) {
	sf::Vector2i drag_start;
	sf::Vector2i new_mouse = sf::Mouse::getPosition(w);

	if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Middle) {
		s.is_dragging = false;
	}

	// If user is dragging, update camera position.
	if (s.is_dragging) {
		sf::Vector2i drag_delta = s.last_mouse_pos - new_mouse;
		s.cam.offset -= drag_delta;
	}

	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Middle) {
		drag_start = sf::Mouse::getPosition(w);
		s.is_dragging = true;
	}

	s.last_mouse_pos = new_mouse;
}

static void handle_scroll(sf::Event& e, ProgramState& s) {
	if (e.type == sf::Event::MouseWheelScrolled) {
		s.cam.zoomf += e.mouseWheelScroll.delta * ZOOM_MULT;
		s.cam.zoomf = std::max(0.1f, s.cam.zoomf);
	}
}

void handle_input(sf::RenderWindow& w, sf::Event& e, ProgramState& s) {
	handle_dragging(w, e, s);
	handle_scroll(e, s);
}
