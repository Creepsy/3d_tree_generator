#pragma once

#include <string>

#include "components.h"

struct object {
    const std::string name = "unnamed";

    std::vector<vertex> vertices;
    std::vector<face> faces;

    friend std::ostream& operator<<(std::ostream& stream, const object& obj);
};


