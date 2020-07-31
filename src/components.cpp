#include "components.h"

std::ostream& operator<<(std::ostream& stream, const vertex& v) {
    return stream << "v " << v.x << " " << v.y << " " << v.z << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const face& f) {
    stream << "f";
    for(const size_t& id : f) {
        stream << " " << id;
    }

    return stream << std::endl;
}