#include"heap_priority_queue.h"
#include<string>
#include<list>

using namespace std;

template<typename E>
E& Position<E>::operator*() {
    return v->elt;
}

template<typename E>
Position<E> Position<E>::left() const {
    return Position<E>(v->left);
}

template<typename E>
Position<E> Position<E>::right() const {
    return Position<E>(v->right);
}

template<typename E>
Position<E> Position<E>::parent() const {
    return Position<E>(v->parent);
}

template<typename E>
bool Position<E>::isRoot() const {
    return v->parent != NULL;
}

template<typename E>
bool Position<E>::isExternal() const {
    return v-> left == NULL && v->right == NULL;
}