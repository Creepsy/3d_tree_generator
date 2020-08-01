#include <iostream>
#include <fstream>

#include "object.h"

int main() {
    std::ofstream output("test_object.obj");

    size_t index = 1;

    if(!output.is_open()) return -1;

    output << create_cube("test_cube",
     vec{0, 0, 0}, vec{0, 0, 1}, vec{1, 0, 1}, vec{1, 0, 0},
     vec{0, 7, 0}, vec{0, 7, 1}, vec{1, 7, 1}, vec{1, 7, 0}, index);

    output << create_line("test", vec{0.5, 7, 0.5}, vec{2, 11, -1}, index, 0.5, 0.25);
    
    output.close();
    
    return 0;
}