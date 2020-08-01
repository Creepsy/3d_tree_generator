#pragma once

#include <ostream>
#include <vector>

struct vec {
    double x;
    double y;
    double z;

    vec& normalize();
    vec cross_product(const vec& other);

    friend std::ostream& operator<<(std::ostream& stream, const vec& v);
    vec operator-(const vec& other) const;
    vec operator+(const vec& other) const;
    vec operator*(const vec& other) const;
    vec operator/(const vec& other) const;

    vec operator*(const double value) const;
};

typedef std::vector<size_t> face;
std::ostream& operator<<(std::ostream& stream, const face& f);