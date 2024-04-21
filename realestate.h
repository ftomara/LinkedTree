#include <iostream>
#include "queue.h"
using namespace std;
#ifndef REALESTATE_H
#define REALESTATE_H
#pragma once
class realestate
{

private:
    string price;
    string id;
    string type;
    queue<string> info;

public:
    realestate()
    {
    }
    realestate(string ID)
    {
        id=ID;

    }
    void getinfo()
    {
        cout << "Enter Building ID : ";
        cin >> id;
        cout << "Enter Building Type : ";
        cin >> type;
        cout << "Enter Building Price : ";
        cin >> price;
    }
    void AddInfo(string i)
    {
        info.push_back(i);
    }
    void Display()
    {
        // cout << "Building Info :\n";
        cout << "ID : " << id << "\n";
        cout << "Type : " << type << "\n";
        cout << "Price : " << price << "\n";
        info.display();
        cout<<endl;
    }
    void DisplayID()
    {
        cout << "ID : " << id << "\n";

    }
    string getprice()
    {
        return price;
    }
    string getuserid()
    {
        return id;
    }
    bool operator==(realestate u)
    {
        return (id == u.id) ? true : false;
    }
    bool operator!=(realestate u)
    {
        return (id != u.id) ? true : false;
    }
    bool operator<(realestate r)
    {
        return (id < r.id) ? true : false;
    }
    bool operator>(realestate r)
    {
        return (id > r.id) ? true : false;
    }
    // realestate& getprob(string ID)
    // {
    //     return 

    // }
    ~realestate()
    {
    }
};

#endif