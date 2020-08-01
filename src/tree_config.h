#pragma once

struct tree_config
{
    double trunk_length = 7;
    double length_decrease_min = -0.2;
    double length_decrease_max = 0.4;
    double min_length = 1.2;
    
    double max_rotation = 35;
    double min_rotation = -35;

    double start_thickness = 0.5;
    double min_thickness = 0.2;

    double thickness_decrease_min = 0.05;
    double thickness_decrease_max = 0.2;

    size_t max_depth = 10;
    size_t min_depth = 6;
    double add_branch_chance = 0.5;

};
