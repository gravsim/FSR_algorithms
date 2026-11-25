#pragma once
#include "vec2.hpp"
#include "triangle.hpp"


Triangle::Triangle() {
    this->point1 = Vec2();
    this->point2 = Vec2();
    this->point3 = Vec2();
    area = 0;
    update_area();
}


Triangle::Triangle(const Vec2& point1, const Vec2& point2, const Vec2& point3) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    area = 0;
    update_area();
}


void Triangle::update_area() {
    area = point1.get_x() * point2.get_y() - point1.get_y() * point2.get_x();
    area += point2.get_x() * point3.get_y() - point2.get_y() * point3.get_x();
    area += point3.get_x() * point1.get_y() - point3.get_y() * point1.get_x();
    area = fabs(area) / 2;
}


double Triangle::get_area() const {
    return area;
}


Triangle Triangle::operator*(double coefficient) const {
    return Triangle(point1 * coefficient, point2 * coefficient, point3 * coefficient);
}


Triangle Triangle::operator+(const Vec2& vec) const {
    return Triangle(point1 + vec, point2 + vec, point3 + vec);
}


std::ostream& operator<<(std::ostream& out, const Triangle& tri) {
    out << tri.point1 << tri.point2 << tri.point3;
    return out;
}

