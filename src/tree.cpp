#include "tree.h"

#include <random>
#include <math.h>
#include <iostream>

tree::tree(const tree_config& config, const vec& position) {
    size_t index = 1;
    this -> add_branch(config, 0, config.start_thickness, config.trunk_length, 90, 0, position, index);
}

tree::~tree() {
}

std::ostream& operator<<(std::ostream& stream, const tree& t) {
    for(const object& branch : t.branches) {
        stream << branch;
    }

    return stream;
}

double tree::rand_range(const double min, const double max) {
    return (double) rand() / ((double)RAND_MAX / (max - min)) + min; 
}

void tree::add_branch(const tree_config& config, size_t depth, double thickness, double branch_length, double rotation_x, double rotation_y, const vec& position, size_t& index) {
    if(depth >= config.max_depth) return;
    if(depth > config.min_depth && this -> rand_range(0, 1) > config.add_branch_chance) return;

    if(thickness < config.min_thickness) thickness = config.min_thickness;
    if(branch_length < config.min_length) branch_length = config.min_length;

    vec end = this -> point_by_rotation(position, rotation_x, rotation_y, branch_length);

    this -> branches.push_back(create_branch("branch_" + std::to_string(this -> branches.size()), position, end, index, thickness, thickness));
    this -> add_branch(config, ++depth, thickness - this -> rand_range(config.thickness_decrease_min, config.thickness_decrease_max),
     branch_length - this -> rand_range(config.length_decrease_min, config.length_decrease_max), rotation_x + this -> rand_range(config.min_rotation, config.max_rotation), 
     rotation_y + this -> rand_range(config.min_rotation, config.max_rotation), end, index);
    this -> add_branch(config, depth, thickness - this -> rand_range(config.thickness_decrease_min, config.thickness_decrease_max),
     branch_length - this -> rand_range(config.length_decrease_min, config.length_decrease_max), rotation_x + this -> rand_range(config.min_rotation, config.max_rotation), 
     rotation_y + this -> rand_range(config.min_rotation, config.max_rotation), end, index);

}

vec tree::point_by_rotation(const vec& origin, double rotation_x, double rotation_y, double length) {
    vec p = origin;

    p.y += sin(rad(rotation_x)) * length;
    p.x += cos(rad(rotation_y)) * cos(rad(rotation_x)) * length;
    p.z += sin(rad(rotation_y)) * cos(rad(rotation_x)) * length;    

    return p;
}

double tree::rad(double deg) {
    return deg * ((double)M_PI / 180);
}