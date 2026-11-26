#include "specialization.hpp"


Heap<Vec2, Vec2>::Heap(int capacity) {
    this->size = 0;
    if (capacity < 1) {
        this->capacity = 1;
    } else {
        this->capacity = capacity;
    }
    this->pairs = new Vec2[capacity];
}



Heap<Vec2, Vec2>::~Heap() {
    delete[] pairs;
}


void Heap<Vec2, Vec2>::swap(int index1, int index2) {
    Vec2 tmp = pairs[index1];
    pairs[index1] = pairs[index2];
    pairs[index2] = tmp;
}


bool Heap<Vec2, Vec2>::is_full() const {
    return size == capacity;
}


bool Heap<Vec2, Vec2>::is_empty() const {
    return size == 0;
}


void Heap<Vec2, Vec2>::expand() {
    Vec2* new_pairs = new Vec2[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        new_pairs[i] = pairs[i];
    }
    delete[] pairs;
    capacity *= 2;
    pairs = new_pairs;
}


void Heap<Vec2, Vec2>::sift_up(int index) {
    while (index > 0 && pairs[index] < pairs[(index - 1) / 2]) {
        swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}


void Heap<Vec2, Vec2>::sift_down(int index) {
    int max_index = index;
    if (2 * index + 1 < size && pairs[2 * index + 1] < pairs[index]) {
        max_index = 2 * index + 1;
    }
    if (2 * index + 2 < size && pairs[2 * index + 2] < pairs[max_index]) {
        max_index = 2 * index + 2;
    }
    if (max_index != index) {
        swap(index, max_index);
        sift_down(max_index);
    }
}


void Heap<Vec2, Vec2>::push(Vec2 Vec2) {
    if (is_full()) {
        expand();
    }
    Vec2 pair = Vec2;
    pairs[size] = pair;
    sift_up(size);
    size++;
}


int Heap<Vec2, Vec2>::find_value(Vec2 vec) {
    int i = 0;
    while (i < size && (pairs[i] == vec)) {
        i++;
    }
    return i;
}


void Heap<Vec2, Vec2>::change(Vec2 old_Vec2, Vec2 new_vec) {
    int index = find_value(old_Vec2);
    pairs[index] = new_vec;
    if (new_vec < old_Vec2) {
        sift_up(index);
    } else {
        sift_down(index);
    }
}


Vec2 Heap<Vec2, Vec2>::get_minimum() {
    return pairs[0];
}


Vec2 Heap<Vec2, Vec2>::pop_minimum() {
    if (is_empty()) {
        std::cout << "Heap is empty! ";
        return Vec2();
    }
    Vec2 Vec2 = pairs[0];
    pairs[0] = pairs[--size];
    sift_down(0);
    return Vec2;
}
