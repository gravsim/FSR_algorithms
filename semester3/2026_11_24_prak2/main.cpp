#include<iostream>
#include "triangle.hpp"
#include "vo"
#include "cmath"




int main() {
    Triangle tri1 = Triangle(Vec2(0, 0), Vec2(0, 1), Vec2(1, 0));
    Triangle tri2 = Triangle(Vec2(10, 0), Vec2(10, 2), Vec2(12, 0));
    Area_comparator area_cmp = Area_comparator();
    RL_comparator rl = RL_comparator();
    std::cout << tri1.get_area() << "\n";
    std::cout << "Area cmp: " << area_cmp.compare(tri1, tri2) << "\n";
    std::cout << "RL: " << rl.compare(tri1, tri2) << "\n";

    return 0;
}
