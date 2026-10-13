#include <iostream>
#include "vec2_lib.cpp"


// Примеры групп: угол, vec2, матрицы

int main() {
    Vec2 vec1;
    std::cin >> vec1;
    std:: cout << vec1;
    Vec2 vec2 = -vec1 - Vec2(1, 1);
    std:: cout << vec2;
    std:: cout << vec1.get_norm() << "\n";
    std:: cout << vec2.get_norm() << "\n";
    return 0;
}
