#include <Image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"

#include <cstdint>
#include <cstring>
#include <iostream>
#include <malloc.h>

// ---------------------------> Constructors <---------------------------

Image::Image(const std::string inputPath, ColorMode mode) {
  int32_t colorMode = static_cast<int32_t>(mode);
  int     bpp       = 0;

  uint8_t* data = stbi_load(inputPath.c_str(), &width, &height, &bpp, colorMode);

  image_     = std::shared_ptr<uint8_t>(data, stbi_image_free);
  colorMode_ = mode;
}

Image::Image(int32_t width, int32_t height, ColorMode mode)
  : width(width), height(height), colorMode_(mode) 
{
  int32_t colorMode = static_cast<int32_t>(mode);
  image_ = std::shared_ptr<uint8_t>(new uint8_t[width * height * colorMode], stbi_image_free);
}

//-----------------------------------------------------------------------



// ----------------------------> Read/Write <----------------------------

void Image::Write(const std::string outputPath) {
  int32_t colorMode = static_cast<int32_t>(colorMode_);
  stbi_write_png(outputPath.c_str(), width, height, colorMode, image_.get(), width * colorMode);
}

//-----------------------------------------------------------------------



// -----------------------------> Get/Set <------------------------------

void Image::SetPixel(int x, int y, Pixel pixel) {
  size_t byteCount = static_cast<int32_t>(colorMode_);
  uint32_t index   = (x * width + y) * static_cast<int32_t>(colorMode_);

  memcpy(image_.get() + index, pixel.bytes, byteCount);
}

Pixel Image::GetPixel(int x, int y) const {
  Pixel pixel      = {};
  size_t byteCount = static_cast<int32_t>(colorMode_);
  uint32_t index   = (x * width + y) * static_cast<int32_t>(colorMode_);

  memcpy(pixel.bytes, image_.get() + index, byteCount);
  return pixel;
}

//-----------------------------------------------------------------------
