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
    Triangle(const Vec2& point1, const Vec2& point2, const Vec2& point3);
    ~Triangle() = default;
    Vec2 get_point1() {return point1;};
    Vec2 get_point2() {return point2;};
    Vec2 get_point3() {return point3;};
    void update_area();
    double get_area();
};
