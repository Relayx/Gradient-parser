#ifndef LIB_FOXTHINGS_GRADIENT_PARSER_IMAGE
#define LIB_FOXTHINGS_GRADIENT_PARSER_IMAGE

#include <memory>
#include <cstdint>
#include <string>

enum class ColorMode { 
  AUTO = 0,     // 0
  GRAY_SCALE,   // 1
  GRAY_ALPHA,   // 2
  RGB,          // 3
  RGBA          // 4
};

union Pixel {
  struct {
    uint8_t gray;
  } grayScale;

  struct {
    uint8_t gray;
    uint8_t alpha;
  } grayAlpha;

  struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
  } rgb;

  struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
  } rgba;

  uint8_t bytes[4];
};

class Image {
 public:
  int32_t width;
  int32_t height;
  std::shared_ptr<uint8_t> image_;

  Image(const std::string inputPath, ColorMode mode);
  Image(int32_t width, int32_t height, ColorMode mode);
  Image() = default;
  ~Image() = default;

  void Write(const std::string outputPath);

  void SetPixel(int x, int y, Pixel pixel);
  Pixel GetPixel(int x, int y) const;

  void Print();

 private:
  ColorMode colorMode_;
};

#endif // LIB_FOXTHINGS_GRADIENT_PARSER_IMAGE