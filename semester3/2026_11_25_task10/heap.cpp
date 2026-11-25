#include "heap.hpp"


template <class Key, class Value>
Heap<Key, Value>::Heap(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->pairs = new Pair<Key, Value>[capacity];
}


template <class Key, class Value>
Heap<Key, Value>::~Heap() {
    delete[] pairs;
}


template <class Key, class Value>
void Heap<Key, Value>::swap(int index1, int index2) {
    Pair<Key, Value> tmp = pairs[index1];
    pairs[index1] = pairs[index2];
    pairs[index2] = tmp;
}


template <class Key, class Value>
bool Heap<Key, Value>::is_full() const {
    return size == capacity;
}


template <class Key, class Value>
bool Heap<Key, Value>::is_empty() const {
    return size == 0;
}


template <class Key, class Value>
void Heap<Key, Value>::expand() {
    Pair<Key, Value>* new_pairs = new Pair<Key, Value>[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        new_pairs[i] = pairs[i];
    }
    delete[] pairs;
    capacity *= 2;
    pairs = new_pairs;
}


template <class Key, class Value>
void Heap<Key, Value>::sift_up(int index) {
    while (index > 0 && pairs[index].get_key() < pairs[(index - 1) / 2].get_key()) {
        swap(index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}


template <class Key, class Value>
void Heap<Key, Value>::sift_down(int index) {
    int max_index = index;
    if (2 * index + 1 < size && pairs[2 * index + 1].get_key() < pairs[index].get_key()) {
        max_index = 2 * index + 1;
    }
    if (2 * index + 2 < size && pairs[2 * index + 2].get_key() < pairs[max_index].get_key()) {
        max_index = 2 * index + 2;
    }
    if (max_index != index) {
        swap(index, max_index);
        sift_down(max_index);
    }
}


template <class Key, class Value>
void Heap<Key, Value>::push(Key key, Value value) {
    if (is_full()) {
        expand();
    }
    Pair<Key, Value> pair = Pair<Key, Value>(key, value);
    pairs[size] = pair;
    sift_up(size);
    size++;
}


template <class Key, class Value>
int Heap<Key, Value>::find_value(Value value) {
    int i = 0;
    while (i < size && pairs[i].get_value() != value) {
        i++;
    }
    return i;
}


template <class Key, class Value>
void Heap<Key, Value>::change(Value old_value, Value new_value) {
    int index = find_value(old_value);
    pairs[index] = new_value;
    if (new_value < old_value) {
        sift_up(index);
    } else {
        sift_down(index);
    }
}


template <class Key, class Value>
Value Heap<Key, Value>::get_minimum() {
    return pairs[0].get_value();
}


template <class Key, class Value>
Value Heap<Key, Value>::pop_minimum() {
    Value value = pairs[0].get_value();
    pairs[0] = pairs[--size];
    sift_down(0);
    return value;
}
