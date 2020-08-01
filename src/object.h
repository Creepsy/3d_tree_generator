#pragma once

#include <string>

#include "components.h"

struct object {
    const std::string name = "unnamed";

    std::vector<vec> vertices;
    std::vector<face> faces;

    friend std::ostream& operator<<(std::ostream& stream, const object& obj);
};

//bottom-front-left, bottom-back-left, bottom-back-right, bottom-front-right, top-front-left, top-back-left, top-back-right, top-front-right
object create_cube(std::string name, vec bfl, vec bbl, vec bbr, vec bfr, vec tfl, vec tbl, vec tbr, vec tfr, size_t& current_index);
object create_line(std::string name, vec start, vec end, size_t& current_index, const double start_width, const double end_width);