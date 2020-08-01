#include <iostream>
#include <fstream>

#include "tree.h"

int main() {
    std::ofstream output("test_object.obj");

    size_t index = 1;

    if(!output.is_open()) return -1;

    tree_config config = tree_config{};

    config.trunk_length = 20;
    config.length_decrease_min = -2;
    config.length_decrease_max = 3;
    config.min_length = 0.5;
    
    config.max_rotation = 50;
    config.min_rotation = -50;

    config.start_thickness = 1;
    config.max_depth = 25;
    config.min_depth = 12;

    config.add_branch_chance = 0.75;

    tree t{config, vec{0, 0, 0}};

    output << t;
    
    output.close();
    
    return 0;
}