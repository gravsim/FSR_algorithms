#include <iostream>

template <class T>
class Heap {
private:
    void expand();
    void sift_up(int index);
    void sift_down(int index);
    void swap(int index1, int index2);
protected:
    int size;
    int capacity;
    T* values;
public:
    Heap(int size, int capacity);
    ~Heap();
    bool is_full() const;
    bool is_empty() const;

    void push(T value);
    int find_value(T value);
    void change(T old_value, T new_value);
    T get_maximum();
    T pop_maximum();
};
