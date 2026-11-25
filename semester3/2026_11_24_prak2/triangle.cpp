#include<iostream>
#include "vec2.cpp"
#include "triangle.hpp"
#include "cmath"



Triangle::Triangle(const Vec2& point1, const Vec2 point2, const Vec2& point3) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    area = 0;
}


void Triangle::update_area() {
    area = point1.get_x() * point2.get_y() - point1.get_y() * point2.get_x();
    area += point2.get_x() * point3.get_y() - point2.get_y() * point3.get_x();
    area += point3.get_x() * point1.get_y() - point3.get_y() * point1.get_x();
    area = fabs(area) / 2;
}


double Triangle::get_area() {
    update_area();
    return area;
}


class Area_comparator {
public:
    Area_comparator() = default;
    bool compare(Triangle tri1, Triangle tri2) {
        return tri1.get_area() < tri2.get_area();
    };
};


class RL_comparator {
public:
RL_comparator() = default;
    bool compare(Triangle tri1, Triangle tri2) {
        return tri1.get_point1().get_x() < tri2.get_point1().get_x()
        && tri1.get_point2().get_x() < tri2.get_point2().get_x()
        && tri1.get_point3().get_x() < tri2.get_point3().get_x();
    };
};


template <class T>
class Comparator {
public:
    bool compare(T a, T b) {
        return a < b;
    };
};

