#ifndef EXPORT_H_
#define EXPORT_H_

#include <vector>
#include <span>
#include <cstdint>

using std::uint8_t;
using std::uint32_t;

struct Rgba
{
	uint8_t r, g, b, a;
};

struct Extent
{
	uint32_t w, h;
};

struct Image
{
	std::vector<Rgba> pixels;
	Extent extent;
};

Image upscale(std::span<Rgba> input, Extent extent);

#endif /* EXPORT_H_ */
