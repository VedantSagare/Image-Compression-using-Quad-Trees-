#include <iostream>
#include <fstream>
#include "QuadTree.h"

Image loadPGM(const std::string& path) {
    std::ifstream file(path);
    std::string magic;
    int w, h, maxVal;

    file >> magic >> w >> h >> maxVal;
    Image img(w, h);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            file >> img.pixels[i][j];

    return img;
}

void savePGM(const Image& img, const std::string& path) {
    std::ofstream file(path);
    file << "P2\n" << img.width << " " << img.height << "\n255\n";

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++)
            file << img.pixels[i][j] << " ";
        file << "\n";
    }
}

int main() {
    Image img = loadPGM("../data/sample.pgm");
    double threshold = 15.0;

    QuadTree tree(0, 0, img.width, img, threshold);
    tree.build();

    Image compressed(img.width, img.height);
    tree.reconstruct(compressed);

    savePGM(compressed, "../output/compressed.pgm");

    std::cout << "Compression completed!\n";
    return 0;
}
