#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H
template <class T>
struct node
{
    friend ostream &operator<<(ostream &out, node<T> &n);
    T data;
    node *next;
    node():next(NULL){}//,capacity(4),size(0),arr(new T[capacity]){}
    
};
template <typename T>
ostream &operator<<(ostream &os, const node<T> &n)
{
    os << n.data;
    return os;
}
#endif
    // T*arr;
    // size_t currentSize;
    // size_t capacity;