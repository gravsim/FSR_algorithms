#include <iostream>
#include "triangle.cpp"
#include "quicksort.cpp"
#include "container.cpp"


void check_comparators() {
    Triangle tri1 = Triangle(Vec2(0, 0), Vec2(0, 1), Vec2(1, 0));
    Triangle tri2 = Triangle(Vec2(10, 0), Vec2(10, 2), Vec2(12, 0));
    std::cout << tri1.get_area() << "\n";
    std::cout << "Area cmp: " << Area_comparator::compare(tri1, tri2) << "\n";
    std::cout << "RL: " << RL_comparator::compare(tri1, tri2) << "\n";
}


void check_area_comparator() {
    int n = 5;
    Container<Triangle> container = Container<Triangle>(n);
    for (int i = 0; i < n; i++) {
        container[n - i - 1] = Triangle(Vec2(0, 0), Vec2(0, 1), Vec2(1, 0)) * i;
    }
    container[0] = container[n - 2];
    std::cout << "1) Before sort:\n";
    for (int i = 0; i < n; i++) {
        std::cout << container[i].get_area() << " ";
    }
    std::cout << "\n";
    quick_sort<Container<Triangle>, Area_comparator>(container, n, 0, n - 1);
    std::cout << "After sort:\n";
    for (int i = 0; i < n; i++) {
        std::cout << container[i].get_area() << " ";
    }
    std::cout << "\n";
}


void check_RL_comparator() {
    int n = 5;
    Container<Triangle> container = Container<Triangle>(n);
    for (int i = 0; i < n; i++) {
        container[n - i - 1] = Triangle(Vec2(0, 0), Vec2(0, 1), Vec2(1, 0)) + Vec2(i, 0);
    }
    container[0] = container[n - 2];
    std::cout << "2) Before sort:\n";
    for (int i = 0; i < n; i++) {
        std::cout << container[i].get_point1() << " ";
    }
    std::cout << "\n";
    quick_sort<Container<Triangle>, RL_comparator>(container, n, 0, n - 1);
    std::cout << "After sort:\n";
    for (int i = 0; i < n; i++) {
        std::cout << container[i].get_point1() << " ";
    }
    std::cout << "\n";
}


void check_standard_comparator() {
    int n = 10;
    Container<int> container = Container<int>(n);
    for (int i = 0; i < n; i++) {
        container[n - i - 1] = i;
    }
    container[0] = container[n - 2];
    std::cout << "3) Before sort:\n";
    for (int i = 0; i < n; i++) {
        std::cout << container[i] << " ";
    }
    std::cout << "\n";
    quick_sort<Container<int>, Comparator<int>>(container, n, 0, n - 1);
    std::cout << "After sort:\n";
    for (int i = 0; i < n; i++) {
        std::cout << container[i] << " ";
    }
    std::cout << "\n";
}


int main() {
    check_comparators();
    check_area_comparator();
    check_RL_comparator();
    check_standard_comparator();
    return 0;
}
