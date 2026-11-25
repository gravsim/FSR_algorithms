
#include "pair.hpp"


template<class Key, class Value>
Pair<Key, Value>::Pair(Key key, Value value) {
    this->key = key;
    this->value = value;
}


template <class Key, class Value>
bool Pair<Key, Value>::operator<(const Pair& pair) const {
    return key < pair.get_key();
}
