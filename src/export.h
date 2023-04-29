#pragma once

#include <vector>
#include <span>
#include <cstdint>

using std::uint8_t;
using std::uint32_t;

struct Rgba
{
	uint8_t r{0}, g{0}, b{0}, a{0};
};

struct Extent
{
	uint32_t width{0}, height{0};
};

struct Image
{
	std::vector<Rgba> pixels;
	Extent extent;
};

Image upscale(std::span<Rgba const> input, uint32_t scale);
