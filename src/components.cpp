#include "components.h"

#include "math.h"

vec& vec::normalize() {
    double distance = sqrt(this -> x * this -> x + this -> y * this -> y + this -> z * this -> z);

    this -> x /= distance;
    this -> y /= distance;
    this -> z /= distance;

    return *this; 
}

vec vec::cross_product(const vec& other) {
    vec cp{};

    cp.x = this -> y * other.z - this -> z * other.y;
    cp.y = this -> z * other.x - this -> x * other.z;
    cp.z = this -> x * other.y - this -> y * other.x;

    return cp;
}

vec vec::operator-(const vec& other) const {
    return vec{this -> x - other.x, this -> y - other.y, this -> z - other.z};
}
vec vec::operator+(const vec& other) const {
    return vec{this -> x + other.x, this -> y + other.y, this -> z + other.z};
}

vec vec::operator*(const vec& other) const {
    return vec{this -> x * other.x, this -> y * other.y, this -> z * other.z};
}

vec vec::operator/(const vec& other) const {
    return vec{this -> x / other.x, this -> y / other.y, this -> z / other.z};
}

vec vec::operator*(const double value) const {
    return vec{this -> x * value, this -> y * value, this -> z * value};
}

std::ostream& operator<<(std::ostream& stream, const vec& v) {
    return stream << "v " << v.x << " " << v.y << " " << v.z << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const face& f) {
    stream << "f";
    for(const size_t& id : f) {
        stream << " " << id;
    }

    return stream << std::endl;
}