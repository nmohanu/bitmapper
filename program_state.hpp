#include <SFML/System/Vector2.hpp>

#include "camera.hpp"
#include "map.hpp"

#pragma once

struct ProgramState {
	Camera cam;
	Map map;
	sf::Vector2i last_mouse_pos;
	bool is_dragging;
};
