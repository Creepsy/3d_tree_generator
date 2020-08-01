#pragma once

#include <ostream>
#include <vector>

#include "tree_config.h"
#include "object.h"

class tree
{
private:
    std::vector<object> branches;

    static double rand_range(const double min, const double max);

    void add_branch(const tree_config& config, size_t depth, double thickness, double branch_length, double rotation_x, double rotation_y, const vec& position, size_t& index);
    vec point_by_rotation(const vec& origin, double rotation_x, double rotation_y, double length);
    double rad(double deg);
public:
    tree(const tree_config& config, const vec& position);
    ~tree();

    friend std::ostream& operator<<(std::ostream& stream, const tree& t);
};


