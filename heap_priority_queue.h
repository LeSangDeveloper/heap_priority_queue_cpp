#ifndef HEAP_PRIORITY_QUEUE_H
#ifndef HEAP_PRIORITY_QUEUE_H

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
        bool isRoot(const Position & p);
        Position root();
        Position last();
        void addLast(const E& e);
        void removeLast();
        void swap(const Position& p, const Position& q);
};

#endif