#include <iostream>
#include <fstream>

#include "object.h"

//bottom-front-left, bottom-back-left, bottom-back-right, bottom-front-right, top-front-left, top-back-left, top-back-right, top-front-right
object create_cube(std::string name, vertex bfl, vertex bbl, vertex bbr, vertex bfr, vertex tfl, vertex tbl, vertex tbr, vertex tfr, size_t& current_index);

int main() {
    std::ofstream output("test_object.obj");

    size_t index = 1;

    if(!output.is_open()) return -1;

    output << create_cube("test_cube",
     vertex{0, 0, 0}, vertex{0, 0, 1}, vertex{1, 0, 1}, vertex{1, 0, 0},
     vertex{0, 7, 0}, vertex{0, 7, 1}, vertex{1, 7, 1}, vertex{1, 7, 0}, index);

    output << create_cube("test_cube2",
     vertex{0, 7, 0}, vertex{0, 7, 1}, vertex{1, 7, 1}, vertex{1, 7, 0},
     vertex{3, 11, 6}, vertex{3, 11, 7}, vertex{4, 11, 7}, vertex{4, 11, 6}, index);
    
    output.close();
    
    return 0;
}

object create_cube(std::string name, vertex bfl, vertex bbl, vertex bbr, vertex bfr, vertex tfl, vertex tbl, vertex tbr, vertex tfr, size_t& current_index) {
    object cube{name};

    cube.vertices.push_back(bfl);
    cube.vertices.push_back(bbl);
    cube.vertices.push_back(bbr);
    cube.vertices.push_back(bfr);

    cube.vertices.push_back(tfl);
    cube.vertices.push_back(tbl);
    cube.vertices.push_back(tbr);
    cube.vertices.push_back(tfr);

    cube.faces.push_back(face{current_index, current_index + 1, current_index + 2, current_index + 3});
    cube.faces.push_back(face{current_index + 4, current_index + 5, current_index + 6, current_index + 7});
    cube.faces.push_back(face{current_index, current_index + 3, current_index + 7, current_index + 4});
    cube.faces.push_back(face{current_index + 1, current_index + 2, current_index + 6, current_index + 5});
    cube.faces.push_back(face{current_index, current_index + 1, current_index + 5, current_index + 4});
    cube.faces.push_back(face{current_index + 2, current_index + 3, current_index + 7, current_index + 6});

    current_index += 8;

    return cube;
}