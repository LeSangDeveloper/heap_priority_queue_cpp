#ifndef HEAP_PRIORITY_QUEUE_H
#define HEAP_PRIORITY_QUEUE_H

#include<vector>

template<typename E>
class VectorCompleteTree {
    private:
        std::vector<E> V;
    public:
        typedef typename std::vector<E>::iterator Position;
    protected:
        Position pos(int i)
        {return V.begin() + i;}
        int idx(const Position& p) const
        {return p - V.begin();}
    public:
        VectorCompleteTree() : V(1) {}
        int size() const;
        Position left(const Position& p);
        Position right(const Position& p);
        Position parent(const Position& p);
        bool hasLeft(const Position& p);
        bool hasRight(const Position& p);
        bool isRoot(const Position& p);
        Position root();
        Position last();
        void addLast(const E& e);
        void removeLast();
        void swap(const Position& p, const Position& q);
};

template<typename E>
class IsLess {
    public:
    bool operator()(const E v1, const E v2) {
        return v1 < v2;
    }
};

template<typename E, typename C>
class HeapPriorityQueue {
    private:
        VectorCompleteTree<E> T;
        C isLess;
    public:
        int size() const;
        bool empty() const;
        void insert(const E& e);
        const E& min();
        void removeMin();

        typedef typename VectorCompleteTree<E>::Position Position;
};

#endif