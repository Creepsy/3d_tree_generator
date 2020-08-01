#include <iostream>
#include <fstream>

#include "object.h"

//bottom-front-left, bottom-back-left, bottom-back-right, bottom-front-right, top-front-left, top-back-left, top-back-right, top-front-right
object create_cube(std::string name, vertex bfl, vertex bbl, vertex bbr, vertex bfr, vertex tfl, vertex tbl, vertex tbr, vertex tfr);

int main() {
    std::ofstream output("test_object.obj");

    if(!output.is_open()) return -1;

    output << create_cube("test_cube",
     vertex{0, 0, 0}, vertex{0, 0, 1}, vertex{1, 0, 1}, vertex{1, 0, 0},
     vertex{0, 2, 0}, vertex{0, 2, 1}, vertex{1, 2, 1}, vertex{1, 2, 0});
    output.close();
    
    return 0;
}

object create_cube(std::string name, vertex bfl, vertex bbl, vertex bbr, vertex bfr, vertex tfl, vertex tbl, vertex tbr, vertex tfr) {
    object cube{name};

    cube.vertices.push_back(bfl);
    cube.vertices.push_back(bbl);
    cube.vertices.push_back(bbr);
    cube.vertices.push_back(bfr);

    cube.vertices.push_back(tfl);
    cube.vertices.push_back(tbl);
    cube.vertices.push_back(tbr);
    cube.vertices.push_back(tfr);

    cube.faces.push_back(face{1, 2, 3, 4});
    cube.faces.push_back(face{5, 6, 7, 8});
    cube.faces.push_back(face{1, 4, 8, 5});
    cube.faces.push_back(face{2, 3, 7, 6});
    cube.faces.push_back(face{1, 2, 6, 5});
    cube.faces.push_back(face{3, 4, 8, 7});

    return cube;
}