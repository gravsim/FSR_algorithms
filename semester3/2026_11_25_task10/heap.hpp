#pragma once
#include <iostream>
#include "pair.cpp"


template <class Key, class Value>
class Heap {
private:
    void expand();
    void sift_up(int index);
    void sift_down(int index);
    void swap(int index1, int index2);
protected:
    int size;
    int capacity;
    Pair<Key, Value>* pairs;
public:
    explicit Heap(int capacity);
    ~Heap();
    bool is_full() const;
    bool is_empty() const;

    void push(Key key, Value value);
    int find_value(Value value);
    void change(Value old_value, Value new_value);
    Value get_minimum();
    Value pop_minimum();
    friend std::ostream& operator<<(std::ostream& out, const Heap<Key, Value>& heap) {
        for (int i = 0; i < heap.size; i++) {
            out << heap.pairs[i] << " ";
        }
        return out;
    }
};
