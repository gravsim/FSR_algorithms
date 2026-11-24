#include<iostream>
#include "vec2.cpp"
#include "cmath"




class Triangle {
private:
    Vec2 point1;
    Vec2 point2;
    Vec2 point3;
    double area;
public:
    Triangle(Vec2 point1, Vec2 point2, Vec2 point3);
    ~Triangle() = default;
    Vec2 get_point1();
    Vec2 get_point2();
    Vec2 get_point3();
    void update_area();
    double get_area();
};


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


int main() {
    Triangle tri = Triangle(Vec2(0, 0), Vec2(0, 1), Vec2(1, 0));
    std::cout << tri.get_area() << "\n";

    return 0;
}
