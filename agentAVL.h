#include <iostream>
#include "AT.h"
#include "agent.h"
using namespace std;
#ifndef agentAVL_H
#define agentAVL_H
#pragma once
class agentAVL : public AT<agent>
{
public:
    agentAVL() : AT<agent>()
    {
    }
    ~agentAVL()
    {
    }
    int hash(agent a)
    {
        string id = a.getagentid();
        int mid = id.length() / 2;
        int f = (id[mid] - '0') * 10;
        int s = id[mid + 1] - '0';
        // cout<<f<<" "<<s<<endl;
        return ((f * 17 + s * 17) % 23);
    }
    linkedlistnode<agent> *Search(int key, linkedlistnode<agent> *root)
    {
        if (root == nullptr || root->key == key)
            return root;
        else if (root->key > key)
            return Search(key, root->left);
        else if (root->key < key)
            return Search(key, root->right);
        return nullptr;
    }
    bool Search(int key)
    {
        return Search(key, AT<agent>::r) != nullptr;
    }
    linkedlistnode<agent> *insert(linkedlistnode<agent> *root, agent &a)
    {
        if (Search(hash(a)))
        {
            AddToList(a, root);
            return root;
        }
        if (root == NULL)
        {
            root = new linkedlistnode<agent>();
            root->data = a;
            root->key = hash(a);
            root->right = root->left = nullptr;
            return root;
        }
        if (hash(a) < root->key)
            root->left = insert(root->left, a);
        else if (hash(a) > root->key)
            root->right = insert(root->right, a);
        else
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balanceFactor = getBalanceFactor(root);
        if (balanceFactor > 1)
        {
            if (hash(a) < root->left->key)
            {
                return rightRotate(root);
            }
            else if (hash(a) > root->left->key)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balanceFactor < -1)
        {
            if (hash(a) > root->right->key)
            {
                return leftRotate(root);
            }
            else if (hash(a) < root->right->key)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    void Insert(agent &a)
    {
        AT<agent>::r = insert(r, a);
    }
    linkedlistnode<agent> *deletenode(linkedlistnode<agent> *root, agent &a)
    {
        if (root->data == a && !root->isempty())
        {
            root->data = root->head->data;
            DeleteFromList(root->head->data, root);
            return root;
        }
        if (hash(a) == root->key && root->head != nullptr)
        {
            DeleteFromList(a, root);
            return root;
        }
        if (root == NULL)
            return root;
        if (hash(a) < root->key)
            root->left = deletenode(root->left, a);
        else if (hash(a) > root->key)
            root->right = deletenode(root->right, a);
        else
        {
            if ((root->left == NULL) || (root->right == NULL))
            {
                linkedlistnode<agent> *temp = root->left ? root->left : root->right;
                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;
                // free(temp);
                delete temp;
            }
            else
            {
                linkedlistnode<agent> *temp = nodeWithMimumValue(root->right);
                root->key = temp->key;
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balanceFactor = getBalanceFactor(root);
        if (balanceFactor > 1)
        {
            if (getBalanceFactor(root->left) >= 0)
            {
                return rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balanceFactor < -1)
        {
            if (getBalanceFactor(root->right) <= 0)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }
    void Delete(agent &a)
    {

        AT<agent>::r = deletenode(r, a);
    }
    void AddToList(agent &a, linkedlistnode<agent> *root)
    {

        root->push_back(a);
    }
    void DeleteFromList(agent &a, linkedlistnode<agent> *root)
    {

        root->removeByValue(a);
    }
    void printTree(linkedlistnode<agent> *root, string indent, bool last)
    {
        if (root != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }
            cout << root->key << endl;
            root->data.Display();
            cout << "\n------------------------------------\n";
            if (!root->isempty())
            {
                auto *temp = root->head;
                while (temp != nullptr)
                {
                    temp->data.Display();
                    temp = temp->next;
                }
            }
            cout << endl;
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }
    void PrintFromList(agent u)
    {
        Search(hash(u), AT<agent>::r)->data.Display();
        cout << endl;
        Search(hash(u), AT<agent>::r)->dispaly();
    }
    linkedlistnode<agent> *getroot()
    {
        return AT::r;
    }
};

#endif