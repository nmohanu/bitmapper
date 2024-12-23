#include <SFML/System/Vector2.hpp>

#pragma once

struct Camera {
	sf::Vector2i offset = sf::Vector2i(0, 0);
	float zoomf = 1.f;
};
