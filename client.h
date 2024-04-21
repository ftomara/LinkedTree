#include <iostream>
#include "queue.h"
#include "realestate.h"
// #include "agent.h"
using namespace std;
#ifndef CLIENT_H
#define CLIENT_H
#pragma once
class client
{
    friend ostream &operator<<(ostream &out, client u)
    {
        out << "Client Info :\n";
        out << "Name : " << u.name << "\n";
        out << "ID : " << u.id << "\n";
        // if (u.Ag != nullptr)
        // {
        //     out << "Assigned RealEstate Agent : \n"
        //         << "AG Name : " << u.Ag->getagentname() << "\nAG ID : " << u.Ag->getagentid() << endl;
        // }
        if (!u.properities.isempty())
        {
            out << "Client Properitites : \n";
            u.properities.display();
        }
        return out;
    }

private:
    string name;
    string id;
    // agent *Ag;
    queue<realestate *> properities;

public:
    client()
    {
    }
    client(string ID)
    {
        id = ID;
    }
    void getinfo()
    {
        cout << "Enter Your Client Name : ";
        // getline(cin, name);
        cin >> name;
        cout << "Enter Client Your ID : ";
        cin >> id;
        cin.ignore();
    }
    void AddActivity(realestate *p)
    {
        properities.push_back(p);
    }
    void Display()
    {
        cout << "client Info :\n";
        cout << "Name : " << name << "\n";
        cout << "ID : " << id << "\n";
        if (!properities.isempty())
        {
            cout << "client Properitites : \n";
            for (int i = 0; i < properities.getsize(); i++)
            {
                cout << "Building No."<<i+1<<" Info :\n";
                properities[i]->Display();
                cout <<"\n-----------------------------------"<< endl;
            }
        }
    }
    void DisplayID()
    {
        cout << "Name : " << name << endl;
        cout << "ID : " << id << endl;
    }
    string getclientname()
    {
        return name;
    }
    string getclientid()
    {
        return id;
    }
    bool operator==(client u)
    {
        return (id == u.id) ? true : false;
    }
    bool operator!=(client u)
    {
        return (id != u.id) ? true : false;
    }
    ~client()
    {
    }
};

#endif
    // void SetAg(agent* a)
    // {
    //     Ag=a;
    // }