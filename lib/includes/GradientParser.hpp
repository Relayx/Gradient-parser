#ifndef LIB_FOXTHINGS_GRADIENT_PARSER_GRADIENTPARSER
#define LIB_FOXTHINGS_GRADIENT_PARSER_GRADIENTPARSER

#include <memory>
#include <vector>

#include <Image.hpp>

struct Point {
  Point(int x, int y);
  explicit Point() = default;

  int x;
  int y;
};

typedef std::vector<std::vector<bool>> ImageGrid;
typedef std::vector<Point> ImageField;

std::shared_ptr<std::vector<ImageField>> GradientParser(Image& image);

#endif //LIB_FOXTHINGS_GRADIENT_PARSER_GRADIENTPARSER