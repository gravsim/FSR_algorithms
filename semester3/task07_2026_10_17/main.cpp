#include <iostream>
#include "vec2.cpp"
#include "angle.cpp"

// Примеры групп: угол, vec2, матрицы

int main() {
    Vec2 vec1;
    std::cin >> vec1;
    std::cout << vec1 << "\n";
    Vec2 vec2 = ---vec1;
    Vec2 vec3 = -vec1--;
    std::cout << vec2 << "\n";
    std::cout << vec3 << "\n";
    std::cout << vec1.get_norm() << "\n";
    std::cout << vec1.normalized() << "\n";
    std::cout << vec1.normalized().get_norm() << "\n";
    std::cout << vec2.get_norm() << "\n";
    std::cout << (vec1 == vec1 + Vec2(1e-15, 1e-15)) << "\n";
    std::cout << (vec1 == vec1 + Vec2(1e-16, 1e-16)) << "\n";
    return 0;
}
