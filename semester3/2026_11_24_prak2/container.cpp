#pragma once
#include <iostream>


template <class T>
class Container{
private:
    T* array;
    int size;
public:
    explicit Container(int n) : array(new T[n]), size(n){}
    ~Container(){delete[] array; };

    Container(const Container<T>& s): array(new T[s.size]), size(s.size){
        for(int i = 0; i< size; ++i){
            array[i] = s.array[i];
        }
    }

    Container(Container<T>&& s): array(s.array), size(s.size){
        s.array = nullptr;
        s.size = 0;
    }

    const Container<T>& operator=(const Container<T>& s){
        if(this != &s){
            delete[] array;
            size = s.size;
            array = new T[size];
            for(int i = 0; i < size; ++i){
                array[i] = s.array[i];
            }
        }
        return *this;
    }
    const Container<T>& operator=(Container<T>&& s){
        if(this != &s){
            delete[] array;
            array = s.array;
            size = s.size;
            s.array = nullptr;
            s.size = 0;
        }
        return *this;
    }

    T& operator[] (int i){
        return array[i];
    }
    void swap(int i, int j){
        T c = array[i];
        array[i] = array[j];
        array[j] = c;
    }

    void resize(int n){
        T* new_array = new T[size + n];
        for(int i = 0; i < size; ++i){
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        size += n;
    }

    int get_size() const{
        return size;
    };
};

template <class T>
std::istream& operator>>(std::istream& is, const Container<T>& c){
    for(int i = 0; i< c.get_size(); ++i){
        is >> c[i];
    }
    return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Container<T>& c){
    for(int i= 0; i < c.get_size(); ++i){
        if(i) os << ' ';
        os << c[i];
    }
    return os;
}
