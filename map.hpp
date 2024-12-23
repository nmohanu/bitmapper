#include <cstdint>
#include <string>
#include <vector>

#include "texture.hpp"

#pragma once

struct BitBlock {
	uint64_t squares;
	Texture texture;
};

template <typename T>
struct BitMap {
	// Convert array of blocks to array of maps.
	BitMap<BitMap<T>>* to_map() {
		BitMap<BitMap<T>>* ret = new BitMap<BitMap<T>>();
		ret->block[0] = this;
	}

	T* block[64];
	uint64_t instances = 0;
};

struct Layer {
	std::vector<BitMap<BitBlock>> bitmaps;
	std::string name;
};

struct Map {
	std::vector<Layer> layers;
};
