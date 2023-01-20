#include"heap_priority_queue.h"
#include<vector>

using namespace std;

template<typename E>
int VectorCompleteTree<E>::size() const {
    return V.size() -1;
}

template<typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::left(const Position& p) {
    return pos(2*idx(p));
}

template<typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::right(const Position& p) {
    return pos(2*idx(p) + 1);
}

template<typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::parent(const Position& p) {
    return pos(idx(p)/2);
}

template<typename E>
bool VectorCompleteTree<E>::hasLeft(const Position& p) {
    return 2*idx(p) <= size();
}

template<typename E>
bool VectorCompleteTree<E>::hasRight(const Position& p) {
    return 2*idx(p) + 1 <= size();
}

template<typename E>
bool VectorCompleteTree<E>::isRoot(const Position& p) {
    return idx(p) == 1;
}

template<typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::root() {
    return pos(1);
}

template<typename E>
typename VectorCompleteTree<E>::Position VectorCompleteTree<E>::last() {
    return pos(size());
}

template<typename E>
void VectorCompleteTree<E>::addLast(const E& e) {
    V.push_back(e);
}

template<typename E>
void VectorCompleteTree<E>::removeLast() {
    V.pop_back();
}

template<typename E>
void VectorCompleteTree<E>::swap(const Position& p, const Position& q) {
    E e = *q; *q = *p; *p = e;
}

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const {
    return T.size();
}

template<typename E, typename C>
bool HeapPriorityQueue<E, C>::empty() const {
    return size() == 0;
}

template<typename E, typename C>
const E& HeapPriorityQueue<E, C>::min() {
    return *(T.root());
}

template<typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E& e) {
    T.addLast(e);
    Position v = T.last();
    while (!T.isRoot(v)) {
        Position u = T.parent(v);
        if (!isLess(*v, *u)) break;
        T.swap(v, u);
        v = u;
    } 
}

template<typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin() {
    if (size() == 1) T.removeLast();
    else {
        Position u = T.root();
        T.swap(u, T.last());
        while (T.hasLeft(u)) {
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u);
            if (isLess(*v, *u)) {
                T.swap(u, v);
                u = v;
            }
            else break;
        }
    }
}

template class VectorCompleteTree<int>;
template class VectorCompleteTree<double>;
template class VectorCompleteTree<float>;

template class HeapPriorityQueue<int, IsLess<int>>;
template class HeapPriorityQueue<double, IsLess<double>>;
template class HeapPriorityQueue<float, IsLess<float>>;