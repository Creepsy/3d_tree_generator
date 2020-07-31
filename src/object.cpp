#include "object.h"

std::ostream& operator<<(std::ostream& stream, const object& obj) {
    stream << "o " << obj.name << std::endl;

    for(const vertex& v : obj.vertices) {
        stream << v;
    }

    stream << "s off" << std::endl;

    for(const face& f : obj.faces) {
        stream << f;
    }

    return stream;
}