#include <GradientParser.hpp>

#include <iostream>
#include <climits>
#include <cstdint>
#include <vector>
#include <queue>

static const Point Moves[4] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1},
};

Point operator+(const Point& first, const Point& second) {
  return Point(first.x + second.x, first.y + second.y);
}

Point::Point(int x, int y) : x(x), y(y) {}

static void BfsHelper(const Image& image, 
                      std::vector<ImageField>& gradients, 
                      ImageGrid& booked, 
                      Point start
  ) {


  static const int kEpsilon = 5;
  static const int kDistMax = 1000;

  std::queue<Point>           queue;
  std::shared_ptr<ImageField> candidate = std::make_shared<ImageField>();

  queue.push(start);

  int changes  = 0;
  int distance = 0;
  int maxDist  = 0;

  while(!queue.empty()) {
    Point current = queue.front();
    queue.pop();
 
    for (auto move : Moves) {
      Point next = current + move;

      if ((next.x >= image.height || next.x < 0) || 
          (next.y >= image.width  || next.y < 0)) {
        continue;
      }

      if (booked[next.x][next.y]) {
        continue;
      }

      int currentPixel = image.GetPixel(current.x, current.y).grayScale.gray;
      int nextPixel    = image.GetPixel(next.x, next.y).grayScale.gray;

      if (currentPixel == nextPixel) {
        ++distance;
      } else if (nextPixel > currentPixel - kEpsilon && nextPixel < currentPixel + kEpsilon) {
        ++changes;
        maxDist = std::max(distance, maxDist);
        distance = 0;
      } else {
        continue;
      }

      queue.push(next);
      booked[next.x][next.y] = true;

    }

    candidate->push_back(current);
    booked[current.x][current.y] = true;
  }

  if (changes > 0 && maxDist < kDistMax) {
    gradients.push_back(*candidate);
  }
}

std::shared_ptr<std::vector<ImageField>> GradientParser(Image& image) {

  ImageGrid booked(image.height, std::vector<bool>(image.width, false));

  auto gradients = std::make_shared<std::vector<ImageField>>();

  for (int i = 0; i < image.height; ++i) {
    for (int j = 0; j < image.width; ++j) {
      if (!booked[i][j]) {
          BfsHelper(image, *gradients, booked, Point(i, j));
      }
    }
  }

  return gradients;
}
