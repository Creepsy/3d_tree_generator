#include <iostream>
#include <fstream>

#include "tree.h"

int main() {
    srand(time(nullptr));

    std::ofstream output("test_object.obj");

    size_t index = 1;

    if(!output.is_open()) return -1;

    tree_config config = tree_config{};

    config.trunk_length = 20;
    config.length_decrease_min = -0.25;
    config.length_decrease_max = 3;
    config.min_length = 0.5;
    
    config.max_rotation = 25;
    config.min_rotation = -25;

    config.start_thickness = 2;
    config.thickness_decrease_min = 0.1;
    config.thickness_decrease_max = 0.3;
    config.max_depth = 18;
    config.min_depth = 10;

    config.add_branch_chance = 0.25;

    tree t{config, vec{0, 0, 0}};

    output << t;
    
    output.close();
    
    return 0;
}