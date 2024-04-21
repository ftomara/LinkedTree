#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;
#include "node.h"
#ifndef linkedlist1_H
#define linkedlist1_H
template <class T>
struct linkedlist1
{

    node<T> *head;
    linkedlist1()
    {
        head = NULL;
    }
    virtual bool isempty()
    {
        return ((head == NULL) ? true : false);
    }
    virtual void push_front(T newitem)
    {
        node<T> *newnode = new node<T>();
        newnode->data = newitem;
        if (isempty())
        {
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    virtual void push_back(T newitem)
    {

        if (isempty())
            push_front(newitem);
        else
        {
            node<T> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node<T> *newnode = new node<T>();
            newnode->data = newitem;
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
    void push_pos(T replace, T original)
    {
        if (searchByValue(original))
        {

            // node<T> *temp = searchByValue(original);
            node<T> *temp = head;
            node<T> *newnode = new node<T>();
            newnode->data = replace;
            while (temp->next->data != original && temp != NULL)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
            cout << "Not Found!\n";
    }
    virtual void dispaly()
    {
        node<T> *temp = head;
        cout << "\n-------------------\n";
        while (temp != NULL)
        {
            cout << temp->data;
            cout << "\n-------------------\n";
            temp = temp->next;
        }
    }
    virtual void dispaly(node<T> *temp)
    {

        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

        cout << temp->data;
        cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    int count()
    {
        node<T> *temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    template <typename Y>
    node<T> *searchByPos(Y pos)
    {
        node<T> *temp = head;
        size_t counter = 1;
        while (counter != pos)
        {
            temp = temp->next;
            counter++;
        }

        return temp;
    }
    template <typename Y>
    node<T> *searchByValue(Y value)
    {
        node<T> *temp = head;
        int pos = 0;
        while (temp != NULL)
        {

            if (temp->data == value)
            {
                // cout << " found at postion : " << pos << "\n";
                return temp;
            }
            temp = temp->next;
            pos++;
        }
        // cout << "NOT FOUND ! \n";
        return nullptr;
    }
    template <typename Y>
    void removeByPos(Y pos)
    {
   
        if (isempty())
        {
            cout << "Your List Is Empty ,Nothing to Delete\n";
            return;
        }
        node<T> *temp = head;
        node<T> *prev = nullptr;
        bool found = false;
        size_t counter = 1;
        if(pos == 1)
        {
            head= head->next;
            return ;

        }
        while (temp != nullptr)
        {
            if (counter == pos)
            {
                if (prev == nullptr)
                {

                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                delete temp;
                found = true;
                // cout << "Value : " << value << "' removed.\n";
                break;
            }
            counter--;
            prev = temp;
            temp = temp->next;
        }

        if (!found)
        {
            cout << "Not Found.\n";
        }
    }
    virtual void pop_up()
    {
        removeByPos(count());
    }
    template <typename Y>
    void removeByValue(Y value)
    {

        if (isempty())
        {
            cout << "Your List Is Empty ,Nothing to Delete\n";
            return;
        }
        node<T> *temp = head;
        node<T> *prev = nullptr;
        node<T> *dn = nullptr;
        if(temp->data == value)
        {
            head=temp->next;
            delete temp;
            return;          
        }
        while(temp->next->next->data != value)
            temp=temp->next;
        prev=temp->next;
        dn=temp->next->next;
        prev->next = dn->next;
        delete dn;    
        // bool found = false;

        // while (temp != nullptr)
        // {
        //     if (temp->data == value)
        //     {
        //         if (prev == nullptr)
        //         {

        //             head = temp->next;
        //         }
        //         else
        //         {
        //             prev->next = temp->next;
        //         }

        //         delete temp;
        //         found = true;
        //         // cout << "Value : " << value << "' removed.\n";
        //         break;
        //     }

        //     prev = temp;
        //     temp = temp->next;
        // }

        // if (!found)
        // {
        //     cout << "Not Found.\n";
        // }
    }
    node<T> *begin()
    {
        // cout << head->data;
        return head;
    }
    node<T> *end()
    {
        // node<T> *temp = head;
        // node<T> *prev = NULL;
        // while (temp->next != NULL)
        // {
        //     prev = temp;
        //     temp = temp->next;
        // }
        // cout << prev->data;
        return nullptr;
    }
    void pre(T value)
    {
        node<T> *prev = NULL;
        node<T> *front = head;
        while (front->data != value)
        {
            prev = front;
            front = front->next;
        }
        if (front == head)
        {
            cout << "The node does not exist";
        }
        else
        {
            cout << prev->data;
        }
    }
    void next(T value)
    {

        node<T> *front = head;
        while (front->data != value)
        {
            front = front->next;
        }
        if (front->next == nullptr)
        {
            cout << "The node does not exist";
        }
        else
        {
            cout << front->next->data;
        }
    }
    void merge(linkedlist1 ob)
    {
        node<T> *temp = ob.head;
        while (temp != NULL)
        {
            push_back(temp->data);
            temp = temp->next;
            
        }
    }
    void reverse()
    {
        node<T> *prev = NULL;
        node<T> *curr = head;
        node<T> *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    node<T> *mergeforsort(node<T> *left, node<T> *right)
    {

        if (!left)
            return right;
        if (!right)
            return left;

        node<T> *result = nullptr;
        if (left->data <= right->data)
        {
            result = left;
            result->next = mergeforsort(left->next, right);
        }
        else
        {
            result = right;
            result->next = mergeforsort(left, right->next);
        }

        return result;
    }
    node<T> *mergeSort(node<T> *head)
    {
        if (!head || !head->next)
            return head;

        node<T> *slow = head;
        node<T> *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        node<T> *mid = slow->next;
        slow->next = nullptr;

        node<T> *left = mergeSort(head);
        node<T> *right = mergeSort(mid);

        return mergeforsort(left, right);
    }
    void swapp(node<T> *&head, node<T> *left, node<T> *right) // node<T>*&head ,
    {
        if (left == right || left == nullptr || right == nullptr)
            return;
        node<T> *prevleft = head;
        node<T> *prevright = head;
        while (prevleft->next != left)
            prevleft = prevleft->next;
        // prevleft->next = right;
        while (prevright->next != right)
            prevright = prevright->next;
        // prevright->next = left;
        if (!prevleft || !prevright)
        {

            if (prevleft == nullptr)
            {
                head = right;
            }
            else
            {
                head = left;
            }
        }
        else
        {
            prevleft->next = right;
            prevright->next = left;
        }
        node<T> *temp = left->next;
        left->next = right->next;
        right->next = temp;
        // if((left==head || right==head)&&(left->next==right || right->next==left))
        // {

        // }
        // else if(left==head || right==head)
        // {

        // }
    }
    void kthnode(size_t index)
    {
        size_t pos = count() - index;
        assert(pos >= 0 && pos < count());
        node<T> *temp = head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        cout << temp->data;
    }
    void twosorted(linkedlist1 &list)
    {
        node<T> *temp = head;
        node<T> *sectemp = NULL;
        merge(list);
        T d;
        node<T>* s = nullptr;
        while(temp!=NULL)
        {
            d= temp->data;
            sectemp =temp->next;
            s=temp;
            while(sectemp!= NULL)
            {
                if(d > sectemp->data )
                {
                      d = sectemp->data;
                      s = sectemp;

                }
                sectemp=sectemp->next;
            }
            s->data=temp->data;
            temp->data=d;
            temp=temp->next;
        }

    }
   
   
    linkedlist1<T> *split()
    {
        linkedlist1<T> *l = new linkedlist1();
        // node<T>* head2;
        node<T> *temp = head;
        for (int i = 1; i < count() / 2; i++)
            temp = temp->next;
        l->head = temp->next;
        temp->next = nullptr;
        // l->dispaly();
        return l;
    }
    ~linkedlist1()
    {
        while (head != nullptr)
        {
            node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
#endif
// bool isfound(T value)
// {
//     node<T> *temp = head;

//     while (temp != NULL)
//     {

//         if (temp->data == value)
//         {
//             // cout << temp->data;
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
    // // list 1 ( 2,5,7)  list 2 (3,1,23)
    // void mergesorted(linkedlist1<int> ll1,linkedlist1 ls2){
    //     linkedlist1<int> * temp1=ll1.head;
    //     linkedlist1<int> * temp2=ls2.head;
    //     for (size_t i = 0; i < ll1.count(); i++)
    //     {
    //         for (size_t i = 0; i < ls2.count(); i++)
    //         {
    //             if (temp1->head->)
    //             {
    //                 /* code */
    //             }
                
    //         }
            
    //         /* code */
    //     }
        

    // }
// }
    // void twosorted(linkedlist1 &list)
    // {
    //     node<T> *temp = head;
    //     node<T> *sectemp = NULL;
    //     node<T> *prevtemp = NULL;
    //     node<T> *prevsec = NULL;
    //     T d = list.head->data;
    //     merge(list);
    //     while (temp->next)
    //     {
    //         if(temp->next->data == d)
    //           prevsec=temp->next;
    //         if(temp->data == d)
    //         {
    //             sectemp = temp;
    //             break;
    //         }
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     while(temp->next)
    //     {
    //         if(sectemp->data <= temp->data)
    //         {
    //             swap(head , temp , sectemp);
    //             temp = prevtemp->next->next;
    //             prevtemp=sectemp;
    //             sectemp= prevsec->next;
    //         }
    //         else
    //         {      
    //             swap(head , sectemp , temp);
    //             sectemp = prevsec->next->next;
    //             prevsec=temp;
    //             temp= prevtemp->next;
    //         }
    //     }
        // linkedlist1 newl;
        // int c = max(count() , list.count());
        // while (c--)
        // {
        //     if (a->data <= b->data)
        //     {
        //         newl.push_back(a->data);
        //         a = a->next;
        //     }
        //     else
        //     {
        //         newl.push_back(b->data);
        //         b = b->next;
        //     }
        // }
        // head= newl.head;
    // }