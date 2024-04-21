#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;
#ifndef queue_H
#define queue_H

template <class T>
struct queue 
{
    friend ostream &operator<<(ostream &out, const queue<T> &q)
    {
        for (int i = q.front; i <= q.rear; i = (i + 1) % q.capacity)
            out << q.Narr[i] << " ";
        return out;
    }

    size_t front;
    size_t rear;
    T *Narr;
    size_t size;
    size_t capacity;
    // int index;

    queue();
    void push_back(T value);
    T pop_front();
    virtual size_t default_capacity();
    bool isempty();
    bool isfull();
    void resize();
    void display() const ;
    void push_pos(size_t i, const T &value);
    void removeByPos(size_t i);
    T &operator[](const size_t pos);
    int getsize();
    int getcapacity();
    int getrear();
    // ~queue();
};

template <class T>
queue<T>::queue()
{
    size = 0;
    capacity = default_capacity();
    Narr = new T[capacity];
    front = rear = 0;
}

template <class T>
void queue<T>::push_back(T value)
{
    if (isfull()) // when commented result in weird behavior and segmentation fault 
        resize();
    Narr[rear] = value;
    rear = (rear + 1) % capacity;
    size++;
}

template <class T>
T queue<T>::pop_front()
{
    // T *rm = new T();
    // rm = &Narr[front];
    T rm = Narr[front]; 
    front = (front + 1) % capacity;
    size--;
    if (isempty())// added new :   if (isempty())
    {
        rear = front = 0;
    }
    // if (size * 3 < capacity)
    //     resize();
    return rm;
}

template <class T>
size_t queue<T>::default_capacity()
{
    return 6; // if changed to less than 5 causes infinty loop too
}

template <class T>
bool queue<T>::isempty()
{
    return (front == rear || size == 0); // added new :  size == 0
}

template <class T>
bool queue<T>::isfull()
{
    return (size + 1 == capacity || ((rear + 1) % capacity == front));// added new : ((rear + 1) % capacity == front)
}

template <class T>
void queue<T>::resize()
{
    size_t newcapacity = max(size * 2, (size_t)2);
    T *newarr = new T[newcapacity];
    for (int i = 0; i < size; i++)
        newarr[i] = Narr[(front + i) % capacity];
    delete [] Narr; // updaated
    Narr = newarr;
    capacity = newcapacity;
    front = 0;
    rear = size;
}

template <class T>
void queue<T>::display() const
{
    for (int i = front; i != rear; i = (i + 1) % capacity)
        cout << Narr[i] << " ";
    // front = (front + 1) % capacity;
}

// template <class T>
// void queue<T>::push_pos(size_t i, const T &value)
// {
//     if (isfull())
//         resize();
//     if (i < size / 2)
//     {
//         front = (front == 0) ? capacity - 1 : front - 1;
//         for (int k = 0; k < i; k++)
//             Narr[(front + k) % capacity] = Narr[(front + k + 1) % capacity];
//     }
//     else
//     {
//         for (int k = size; k > i; k--)
//             Narr[(front + k) % capacity] = Narr[(front + k - 1) % capacity];
//     }
//     size++;
//     Narr[(front + i) % capacity] = value;
// }

template <class T>
void queue<T>::removeByPos(size_t i)
{
    if (i < size / 2)
    {
        for (int k = i - 1; k >= 0; k--)
            Narr[(front + k + 1) % capacity] = Narr[(front + k) % capacity];
        front = (front + 1) % capacity;
    }
    else
    {
        for (int k = i; k < size - 1; k++)
            Narr[(front + k) % capacity] = Narr[(front + k + 1) % capacity];
        // rear = (rear+1)%capacity;
        rear = (rear - 1 + capacity) % capacity; 
    }
    size--;
    if (size * 3 < capacity)
        resize();
}

template <class T>
T &queue<T>::operator[](const size_t pos)
{
    if (pos >= size)
        throw out_of_range("postion is out of range");
    return Narr[pos];
}

template <class T>
int queue<T>::getsize()
{
    return size;
}

template <class T>
int queue<T>::getcapacity()
{
    return capacity;
}
template <class T>
int queue<T>::getrear()
{
    return rear;
}

// template <class T>
// queue<T>::~queue()
// {
//     delete [] Narr ;
// }

#endif
