#include <iostream>
#include "queue.h"
#include "realestate.h"
#include "client.h"
using namespace std;
#ifndef AGENT_H
#define AGENT_H
#pragma once
class agent
{
    friend ostream &operator<<(ostream &out, agent u)
    {
        out << "Agent Info :\n";
        out << "Name : " << u.name << "\n";
        out << "ID : " << u.id << "\n";
        out << "Rate : " << u.rate << "\n";
        if (!u.properities.isempty())
        {
            out << "Agent Properitites : \n";
            u.properities.display();
        }
        if (!u.clients.isempty())
        {
            out << "Agent's Clients : \n";
            u.properities.display();
        }
        return out;
    }

private:
    string name;
    string id;
    string rate;
    queue<realestate *> properities;
    queue<client *> clients;

public:
    agent()
    {
    }
    agent(string ID)
    {
        id = ID;
    }
    void getinfo()
    {
        cout << "Enter Your Name : ";
        cin >> name;
        cout << "Enter Your ID : ";
        cin >> id;
        cout << "Enter Your Rate : ";
        cin >> rate;
        cin.ignore();
    }
    void AddProberity(realestate *p)
    {
        properities.push_back(p);
    }
    void AddClients(client *c)
    {
        clients.push_back(c);
    }
    void Display()
    {
        cout << "Agent Info :\n";
        cout << "-----------------------------------" << endl;
        cout << "Name : " << name << "\n";
        cout << "ID : " << id << "\n";
        cout << "Rate : " << rate << "\n";
        cout << "-----------------------------------" << endl;
        if (!properities.isempty())
        {
            cout << "Agent Properitites : \n";
            DisplayProberites();
        }
        cout << "-----------------------------------" << endl;
        if (!clients.isempty())
        {
            Displayclients();
        }
    }
    void Displayclients()
    {

        for (int i = 0; i < clients.getsize(); i++)
        {
            cout << "Client No." << i + 1 << " Info :\n";
            clients[i]->Display();
            cout << "\n-----------------------------------" << endl;
        }
    }
    void DisplayProberites()
    {

        for (int i = 0; i < properities.getsize(); i++)
        {
            cout << "Building No." << i + 1 << " Info :\n";
            properities[i]->Display();
            cout << "\n-----------------------------------" << endl;
        }
    }
    string getagentname()
    {
        return name;
    }
    string getagentid()
    {
        return id;
    }
    bool operator==(agent u)
    {
        return (id == u.id) ? true : false;
    }
    bool operator!=(agent u)
    {
        return (id != u.id) ? true : false;
    }
    void delete_client(client c)
    {
        for (int i = 0; i < clients.getsize(); i++)
        {
            if (clients[i]->getclientid() == c.getclientid())
            {
                clients.removeByPos(i);
                cout << "Client With ID : " << clients[i]->getclientid() << "Removed !\n";
                break;
            }
        }
    }
    void delete_prob(realestate r)
    {
        for (int i = 0; i < properities.getsize(); i++)
        {
            if (properities[i]->getuserid() == r.getuserid())
            {
                properities.removeByPos(i);
                cout << "Proberity With ID : " << properities[i]->getuserid() << "Removed !\n";
                break;
            }
        }
    }
    ~agent()
    {
    }
};

#endif