#include <iostream>
#include "vec2.cpp"
#include "angle.cpp"


double deg_cos(double angle) {
    return cos(angle * PI / 180);
}

double deg_sin(double angle) {
    return sin(angle * PI / 180);
}


int main() {
    Vec2 a = Angle(45);
    Angle b = Vec2(0, 1);
    std::cout << a << "\n";
    std::cout << b << "\n";
    std::cout << Vec2(5, Angle(45)) << "\n";
    std::cout << -(a + ++b) / 2.0 - Vec2(5, Angle(70))-- << "\n";
    std::cout << "x: " << -deg_cos(45 + 91) / 2.0 - 5 * deg_cos(70) + 1;
    std::cout << "y: " << -deg_sin(45 + 91) / 2.0 - 5 * deg_sin(70) + 1 << "\n";
    return 0;
}
