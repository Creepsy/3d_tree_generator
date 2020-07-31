#pragma once

#include <ostream>
#include <vector>

struct vertex {
    double x;
    double y;
    double z;

    friend std::ostream& operator<<(std::ostream& stream, const vertex& v);
};

struct face {
    std::vector<vertex> vertices;

    friend std::ostream& operator<<(std::ostream& stream, const face& f);
};
