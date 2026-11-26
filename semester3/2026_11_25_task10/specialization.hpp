#pragma once
#include <iostream>
#include "heap.cpp"
#include "vec2.cpp"


template <>
class Heap<Vec2, Vec2> {
private:
    void expand();
    void sift_up(int index);
    void sift_down(int index);
    void swap(int index1, int index2);
protected:
    int size;
    int capacity;
    Vec2* pairs;
public:
    explicit Heap(int capacity);
    ~Heap();
    bool is_full() const;
    bool is_empty() const;

    void push(Vec2 value);
    int find_value(Vec2 value);
    void change(Vec2 old_value, Vec2 new_value);
    Vec2 get_minimum();
    Vec2 pop_minimum();
    friend std::ostream& operator<<(std::ostream& out, const Heap<Vec2, Vec2>& heap) {
        for (int i = 0; i < heap.size; i++) {
            out << heap.pairs[i] << " ";
        }
        return out;
    }
};
