#include <iostream>
#include"queue.h"
#include "linkedlist1.h"
using namespace std;
#ifndef linkedlistnode_H
#define linkedlistnode_H
template <class T>
struct linkedlistnode : public linkedlist1<T> 
{
    linkedlistnode<T> *left;
    linkedlistnode<T> *right;
    int key;
    T data;
    int height;
    linkedlistnode():linkedlist1<T>(),left(NULL),right(NULL),height(1){}
    void operator=(linkedlistnode<T>* q)
    {
        left =q->left;
        right=q->right;
        key=q->key;
        data =q->data;
        height =q->height;
    }

};
#endif
    // friend ostream &operator<<(ostream &out, linkedlistnode<T> &n);

// template <typename T>
// ostream &operator<<(ostream &os, linkedlistnode<T> &n)
// {
//     os << n.linkelist1<T>::display();
//     return os;
// }
  
    // linkedlistnode<T> *next;
    // linkedlist1<T> l;
    // linkedlistnode(int val):queue<T>(),next(NULL),left(NULL),right(NULL),parent(NULL){key= val; height=1;}
    // linkedlistnode<T> *parent;