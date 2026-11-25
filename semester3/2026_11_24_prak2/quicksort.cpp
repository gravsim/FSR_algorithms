#pragma once
#include "container.cpp"


template <class Container, class Comparator>
void quick_sort(Container& c, int n, int left, int right){
    if (left >= right){
        return;
    }
    auto pivot = c[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j){
        while (Comparator::compare(c[i], pivot) < 0){
            i++;
        }
        while (Comparator::compare(c[j], pivot) > 0){
            j--;
        }
        if (i <= j){
            c.swap(i, j);
            i++;
            j--;
        }
    }
    quick_sort(c, n, left, j);
    quick_sort(c, n, i, right);
}
