#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <fstream>

using std::uint8_t;
using std::uint32_t;

struct Rgba
{
	Rgba(uint32_t hex);
	Rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	uint8_t r{0}, g{0}, b{0}, a{0};
	static constexpr uint32_t to_hex(const Rgba &rgba);
};

struct Index2D
{
	uint32_t x{0}, y{0};
};

struct Extent
{
	uint32_t width{0}, height{0};
};

struct Image
{
	Image(uint32_t width, uint32_t height);
	static void export_to_ppm(const Image &input, const std::string &path);
	Rgba &operator[](Index2D index);
	const Rgba &operator[](Index2D index) const;
	
	Extent extent;
	std::vector<Rgba> pixels;
};

Image upscale(const Image &input, uint32_t scale);