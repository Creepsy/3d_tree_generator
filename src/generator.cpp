#include <iostream>

#include "object.h"

int main() {
    object cube = {"cube"};

    cube.vertices.push_back(vertex{0, 0, 0});
    cube.vertices.push_back(vertex{0, 1, 0});
    cube.vertices.push_back(vertex{1, 0, 0});
    cube.vertices.push_back(vertex{1, 1, 0});

    cube.vertices.push_back(vertex{0, 0, 1});
    cube.vertices.push_back(vertex{0, 1, 1});
    cube.vertices.push_back(vertex{1, 0, 1});
    cube.vertices.push_back(vertex{1, 1, 1});

    cube.faces.push_back(face{1, 2, 4, 3});
    cube.faces.push_back(face{5, 6, 8, 7});
    cube.faces.push_back(face{1, 5, 6, 2});
    cube.faces.push_back(face{3, 7, 8, 4});
    cube.faces.push_back(face{2, 4, 8, 6});
    cube.faces.push_back(face{1, 3, 7, 5});

    std::cout << cube;
    return 0;
}