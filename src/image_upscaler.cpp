#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include <image_upscaler/image_upscaler.hpp>

/* Implementation of Rgba */
Rgba::Rgba(uint32_t hex) : r((hex & 0xFF'00'00'00) >> 24), g((hex & 0x00'FF'00'00) >> 16), b((hex & 0x00'00'FF'00) >> 8), a(hex & 0x00'00'00'FF) {}

Rgba::Rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}

constexpr uint32_t Rgba::to_hex(Rgba const& rgba) { return ((rgba.r << 24) | (rgba.g << 16) | (rgba.b << 8) | (rgba.a)); }

/* --- End --- */

/* Implementation of Image */
Image::Image(uint32_t width, uint32_t height) : extent{width, height}, pixels(width * height, Rgba(0)) {}

void Image::export_to_ppm(Image const& input, std::string const& path) {
	std::ofstream output(path);
	output << "P3\n";
	output << "# " << path << '\n';
	output << input.extent.width << " " << input.extent.height << '\n';
	output << "255\n";

	for (uint32_t y = 0; y < input.extent.height; ++y) {
		for (uint32_t x = 0; x < input.extent.width; ++x) {
			Rgba current = input.pixels.at(y * input.extent.width + x);
			output << static_cast<uint32_t>(current.r) << '\n' << static_cast<uint32_t>(current.g) << '\n' << static_cast<uint32_t>(current.b) << '\n';
		}
	}

	output.close();
}

Rgba& Image::operator[](Index2D index) { return this->pixels.at(index.y * this->extent.width + index.x); }

Rgba const& Image::operator[](Index2D index) const { return this->pixels.at(index.y * this->extent.width + index.x); }

/* --- End --- */

Image upscale(Image const& input, uint32_t scale) {
	uint32_t target_width_v = input.extent.width * scale;
	uint32_t target_height_v = input.extent.height * scale;
	uint32_t x_index{0}, y_index{0};
	Image target_image(target_width_v, target_height_v);

	for (y_index = 0; y_index < input.extent.height; ++y_index) {
		for (x_index = 0; x_index < input.extent.width; ++x_index) {
			Rgba current = input[Index2D{x_index, y_index}];
			if (Rgba::to_hex(current)) {
				for (uint32_t i = y_index * scale; i < ((y_index + 1) * scale); ++i) {
					for (uint32_t j = x_index * scale; j < ((x_index + 1) * scale); ++j) { target_image[Index2D{j, i}] = current; }
				}
			}
		}
	}

	return target_image;
}
