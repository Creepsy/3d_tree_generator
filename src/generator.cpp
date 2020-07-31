#include <iostream>

#include "object.h"

int main() {
    vertex v = {1.0, 2.34, 4};
    face f = {1, 2, 1};
    std::cout << v << f;
    return 0;
}