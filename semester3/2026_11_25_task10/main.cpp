#include <iostream>
#include "heap.cpp"


int main() {
    Heap<int, double> heap = Heap<int, double>(0);
    heap.push(0, 1.0f);
    heap.push(-1, -4.0f);
    heap.push(1, 100.0f);
    heap.push(4, -100.0f);
    
    std::cout << heap << "\n";
    std::cout << heap.pop_minimum() << "\n";
    std::cout << heap << "\n";
    std::cout << heap.pop_minimum() << "\n";
    std::cout << heap << "\n";
    std::cout << heap.pop_minimum() << "\n";
    std::cout << heap << "\n";
    std::cout << heap.pop_minimum() << "\n";
    std::cout << heap << "\n";
    std::cout << heap.pop_minimum() << "\n";
    std::cout << heap << "\n";
    std::cout << heap.pop_minimum() << "\n";
    return 0;
}
