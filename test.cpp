#include<iostream>
#include"heap_priority_queue.h"

using namespace std;

int main() {
    HeapPriorityQueue<int, IsLess<int> > a;
    a.insert(3);
    cout << a.min() << endl;
    a.insert(1);
    cout << a.min() << endl;
    a.insert(2);
    cout << a.min() << endl;
    a.removeMin();
    cout << a.min() << endl;
    return 0;
}