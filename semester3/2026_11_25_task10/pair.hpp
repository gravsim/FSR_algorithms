#pragma once
#include <iostream>

template <class Key, class Value>
class Pair {
protected:
    Key key;
    Value value;
public:
    Pair() = default;
    Pair(Key key, Value value);
    Key get_key() const {return key;}
    Value get_value() const {return value;}
    bool operator<(const Pair& pair) const;
    Pair& operator=(const Pair& pair) = default;
    friend std::ostream& operator<<(std::ostream& out, const Pair& pair) {
        out << "(Key: " << pair.get_key() << ", Value: " << pair.get_value() << ")";
        return out;
    }
};
