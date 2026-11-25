#include <iostream>
#include "heap.cpp"


int main() {
    Heap<int, double> heap = Heap<int, double>(10);
    heap.push(0, 1.0f);
    heap.push(-1, -4.0f);
    heap.push(1, 100.0f);
    heap.push(4, -100.0f);
    std::cout << heap << "\n";


    return 0;
}
