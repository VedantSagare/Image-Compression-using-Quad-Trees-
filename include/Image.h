#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

struct Image {
    int width, height;
    std::vector<std::vector<int>> pixels;

    Image(int w, int h) : width(w), height(h) {
        pixels.resize(h, std::vector<int>(w, 0));
    }
};

#endif
