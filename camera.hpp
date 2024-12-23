#include <SFML/System/Vector2.hpp>

#pragma once

struct Camera {
	sf::Vector2<int> offset = sf::Vector2(0, 0);
	float zoomf = 1.f;
};
