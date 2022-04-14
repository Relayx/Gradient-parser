#include <iostream>
#include <string>
#include <filesystem>

#include <Image.hpp>
#include <GradientParser.hpp>

namespace fs = std::filesystem;

void Print(Image& image, std::vector<Point>& candidate) {
  for (auto& point : candidate) {
    Pixel pix;
    pix.rgb.red = 255;
    pix.rgb.green = 255;
    pix.rgb.blue = 255;
    image.SetPixel(point.x, point.y, pix);
  }
}

void Execute(std::string inputPath, std::string outputPath) {
    Image image (inputPath, ColorMode::GRAY_SCALE);
    Image result(inputPath, ColorMode::RGB);

    auto gradients = GradientParser(image);

    for (auto& field : *gradients) {
        Print(result, field);
    }

    result.Write(outputPath);
}

int main() {
    std::string path = "";

    std::cout << "Please, write folder with images:" << std::endl;
    std::cin >> path;

    int counter = 0;
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << "Processing:" << std::endl << entry.path() << std::endl;
        Execute(entry.path(), path + "/image_" + std::to_string(counter) + ".png");
        ++counter;
    }

    return 0;
}