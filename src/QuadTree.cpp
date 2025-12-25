#ifndef QUADTREE_H
#define QUADTREE_H

#include "Image.h"

class QuadTree {
public:
    QuadTree(int x, int y, int size, Image& img, double threshold);
    ~QuadTree();

    void build();
    void reconstruct(Image& out);

private:
    int x, y, size;
    double threshold;
    Image& image;
    bool isLeaf;
    int value;

    QuadTree* children[4];

    double variance();
};

#endif
