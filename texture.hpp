#include <cstdint>

struct Rectangle {
	Rectangle(uint32_t x, uint32_t y, uint32_t width, uint32_t height) : x(x), y(y), width(width), height(height) {}
	uint32_t x, y, width, height;
};

struct Texture {
	uint32_t id;
	Rectangle src;
};
