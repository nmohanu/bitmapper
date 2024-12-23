#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>
static sf::Vector2i normalize_veci(sf::Vector2i& vec) {
	if (vec == sf::Vector2i(0, 0)) return vec;
	sf::Vector2i ret;
	ret.x = vec.x / std::sqrt(vec.x * vec.x + vec.y * vec.y);
	ret.y = vec.y / std::sqrt(vec.x * vec.x + vec.y * vec.y);
	return ret;
}
