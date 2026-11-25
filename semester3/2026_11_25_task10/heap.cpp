#include <iostream>
#include "heap.hpp"


template <class T>
Heap<T>::Heap(int size, int capacity) {
    this->size = size;
    this->capacity = capacity;
    this->values = new T[capacity];
}


template <class T>
Heap<T>::~Heap() {
    delete values;
}


template <class T>
void Heap<T>::swap(int index1, int index2) {
    T tmp = values[index1];
    values[index1] = values[index2];
    values[index2] = tmp;
}


template <class T>
bool Heap<T>::is_full() const {
    return size == capacity;
}


template <class T>
bool Heap<T>::is_empty() const {
    return size == 0;
}


template <class T>
void Heap<T>::expand() {
    T* new_values = new T[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        new_values[i] = new_values;
    }
    delete values;
    capacity *= 2;
    values = new_values;
}


template <class T>
void Heap<T>::sift_up(int index) {
    while (index > 0 && values[index] > values[(index - 1) / 2]) {
        swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}


template <class T>
void Heap<T>::sift_down(int index) {
    int max_index = index;
    if (2 * index + 1 < size && values[2 * index + 1] > values[index]) {
        max_index = 2 * index + 1;
    }
    if (2 * index + 2 < size && values[2 * index + 2] > values[max_index]) {
        max_index = 2 * index + 2;
    }
    if (max_index != index) {
        swap(index, max_index);
        sift_down(max_index);
    }
}


template <class T>
void Heap<T>::push(T value) {
    if (is_full()) {
        expand();
    }
    values[size] = value;
    sift_up(size);
    size++;
}


template <class T>
int Heap<T>::find_value(T value) {
    int i = 0;
    while (i < size && values[i] != value) {
        i++;
    }
    return i;
}


template <class T>
void Heap<T>::change(T old_value, T new_value) {
    int index = find_value(old_value);
    values[index] = new_value;
    if (new_value > old_value) {
        sift_up(index);
    } else {
        sift_down(index);
    }
}


template <class T>
T Heap<T>::get_maximum() {
    return values[0];
}


template <class T>
T Heap<T>::pop_maximum() {
    int value = values[0];
    values[0] = values[--size];
    sift_down(0);
    return value;
}


int print_heap(Heap* heap) {
    if (!heap) {
        return -1;
    }
    int i;
    for (i = 0; i < heap->size; i++) {
        printf("%d ", heap->values[i]);
    }
    return 1;
}