#include "object.h"

std::ostream& operator<<(std::ostream& stream, const object& obj) {
    stream << "o " << obj.name << std::endl;

    for(const vec& v : obj.vertices) {
        stream << v;
    }

    stream << "s off" << std::endl;

    for(const face& f : obj.faces) {
        stream << f;
    }

    return stream;
}


object create_cube(std::string name, vec bfl, vec bbl, vec bbr, vec bfr, vec tfl, vec tbl, vec tbr, vec tfr, size_t& current_index) {
    object cube{name};

    cube.vertices.push_back(bfl);
    cube.vertices.push_back(bbl);
    cube.vertices.push_back(bbr);
    cube.vertices.push_back(bfr);

    cube.vertices.push_back(tfl);
    cube.vertices.push_back(tbl);
    cube.vertices.push_back(tbr);
    cube.vertices.push_back(tfr);

    cube.faces.push_back(face{current_index, current_index + 1, current_index + 2, current_index + 3});
    cube.faces.push_back(face{current_index + 4, current_index + 5, current_index + 6, current_index + 7});
    cube.faces.push_back(face{current_index, current_index + 3, current_index + 7, current_index + 4});
    cube.faces.push_back(face{current_index + 1, current_index + 2, current_index + 6, current_index + 5});
    cube.faces.push_back(face{current_index, current_index + 1, current_index + 5, current_index + 4});
    cube.faces.push_back(face{current_index + 2, current_index + 3, current_index + 7, current_index + 6});

    current_index += 8;

    return cube;
}

object create_branch(std::string name, vec start, vec end, size_t& current_index, const double start_width, const double end_width) {
    vec direction = (start - end).normalize();
    vec orthogonal_0 = direction.cross_product(vec{0, 1, 0}).normalize();
    vec orthogonal_1 = orthogonal_0.cross_product(direction).normalize();

    vec bfl = start - orthogonal_0 * start_width + orthogonal_1 * start_width;
    vec bbl = start - orthogonal_0 * start_width - orthogonal_1 * start_width;
    vec bbr = start + orthogonal_0 * start_width - orthogonal_1 * start_width;
    vec bfr = start + orthogonal_0 * start_width + orthogonal_1 * start_width;

    /*vec bfl = vec{start.x - start_width, start.y, start.z - start_width};
    vec bbl = vec{start.x - start_width, start.y, start.z + start_width};
    vec bbr = vec{start.x + start_width, start.y, start.z + start_width};
    vec bfr = vec{start.x + start_width, start.y, start.z - start_width};*/

    /*vec tfl = end - orthogonal_0 * end_width + orthogonal_1 * end_width;
    vec tbl = end - orthogonal_0 * end_width - orthogonal_1 * end_width;
    vec tbr = end + orthogonal_0 * end_width - orthogonal_1 * end_width;
    vec tfr = end + orthogonal_0 * end_width + orthogonal_1 * end_width;*/

    vec tfl = end - orthogonal_0 * end_width + orthogonal_1 * end_width;
    vec tbl = end - orthogonal_0 * end_width - orthogonal_1 * end_width;
    vec tbr = end + orthogonal_0 * end_width - orthogonal_1 * end_width;
    vec tfr = end + orthogonal_0 * end_width + orthogonal_1 * end_width;

    return create_cube(name, bfl, bbl, bbr, bfr, tfl, tbl, tbr, tfr, current_index);
}