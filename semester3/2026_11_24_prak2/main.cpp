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
    Vec2 get_point1() {return point1;};
    Vec2 get_point2() {return point2;};
    Vec2 get_point3() {return point3;};
    void update_area();
    double get_area();
};


Triangle::Triangle(Vec2 point1, Vec2 point2, Vec2 point3) {
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
private:
public:
    Area_comparator() = default;
    bool compare(Triangle tri1, Triangle tri2) {
        return tri1.get_area() < tri2.get_area();
    };
};


class RL_comparator {
private:
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
