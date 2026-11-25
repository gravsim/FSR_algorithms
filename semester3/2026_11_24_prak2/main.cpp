#include <iostream>
#include "triangle.hpp"
#include "vova.cpp"
#include "container.cpp"




int main() {
    Triangle tri1 = Triangle(Vec2(0, 0), Vec2(0, 1), Vec2(1, 0));
    Triangle tri2 = Triangle(Vec2(10, 0), Vec2(10, 2), Vec2(12, 0));
    std::cout << tri1.get_area() << "\n";
    std::cout << "Area cmp: " << Area_comparator::compare(tri1, tri2) << "\n";
    std::cout << "RL: " << RL_comparator::compare(tri1, tri2) << "\n";
    int n = 100;
    Container<Triangle> container = Container<Triangle>(10);
    for (int i = 0; i < n; i++) {
        container[i] = Triangle(Vec2(10 * i, 0), Vec2(10 * i, 2), Vec2(10 * i + 2, 0));
    }
    quick_sort<Container<Triangle>, RL_comparator>(container, n, 0, n - 1);
    return 0;
}
