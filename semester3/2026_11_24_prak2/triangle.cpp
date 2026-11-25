#pragma once
#include "vec2.hpp"
#include "triangle.hpp"


Triangle::Triangle() {
    this->point1 = Vec2();
    this->point2 = Vec2();
    this->point3 = Vec2();
    area = 0;
}


Triangle::Triangle(const Vec2& point1, const Vec2& point2, const Vec2& point3) {
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
