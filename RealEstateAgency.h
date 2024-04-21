#include <iostream>
#include "agentAVL.h"
#include "agent.h"
#include "client.h"
#include "realestate.h"
using namespace std;
#ifndef REALESTATEAGENCY_H
#define REALESTATEAGENCY_H

#pragma once

class RealEstateAgency
{
private:
    realestate prop[10];
    client cl[10];
    int Psize;
    int Clsize;
    agentAVL ag;
    int agcount;

public:
    RealEstateAgency()
    {
        Psize = 0;
        Clsize = 0;
        agcount = 0;
    }
    void addProberity()
    {
        int n;
        cout << "How many Proberites Do you Want to Add ? ( 0 - " << 10 - Psize << ") : ";
        cin >> n;
        bool t = false;
        for (int i = 0; i < n; i++)
        {
            prop[Psize].getinfo();
            string s;
            cout << "Enter Building Address : ";
            cin >> s;
            prop[Psize].AddInfo(s);
            cout << "Enter Building State [Sold , Available] : ";
            cin >> s;
            prop[Psize].AddInfo(s);
            Psize++;
            t = true;
        }
        if (t)
            cout << "Clients Added Succesfully !\n";
        else
            cout << "Error Adding Clients \n";
    }
    void addClient()
    {
        bool t = false;
        int n;
        cout << "How many Clients Do you Want to Add ? ( 0 - " << 10 - Clsize << ") : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cl[Clsize].getinfo();
            if (Psize > 0)
            {
                int f;
                cout << "Do You Want to Add Proberite to This Client? (1-Yes , 0-No) ";
                cin >> f;
                if (f)
                {
                    cout << " Which Proberite ? \n";
                    cout << "--------------------------------\n";
                    for (int i = 0; i < Psize; i++)
                    {
                        cout << i + 1 << ". ";
                        prop[i].DisplayID();
                    }
                    int m;
                    cout << "How many Do You Want To Add ? ";
                    cin >> m;
                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        cl[Clsize].AddActivity(&prop[f - 1]);
                        cout << "Proberite Has Been Added Successfully!\n";
                    }
                }
            }
            Clsize++;
            t = true;
        }
        if (t)
            cout << "Clients Added Succesfully !\n";
        else
            cout << "Error Adding Clients \n";
    }
    void addAgent()
    {
        int n;
        bool t = false;
        cout << "How many Agents Do you Want to Add ? \n ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            agent a;
            a.getinfo();
            if (Psize > 0)
            {
                int f;
                cout << "Do You Want to Add Proberite to This Agent? (1-Yes , 0-No) ";
                cin >> f;
                if (f)
                {
                    cout << " Which Proberity  ? \n";
                    cout << "--------------------------\n";
                    for (int i = 0; i < Psize; i++)
                    {
                        cout << i + 1 << ". ";
                        prop[i].DisplayID();
                    }
                    int m;
                    cout << "How many Do You Want To Add ? ";
                    cin >> m;
                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        a.AddProberity(&prop[f - 1]);
                        cout << "Proberity Has Been Added Successfully!\n";
                    }
                }
            }
            else
                cout << "There is No Proberites To Add !\n";
            if (Clsize > 0)
            {
                int f;
                cout << "Do You Want to Add Clients to This Agent? (1-Yes , 0-No): ";
                cin >> f;
                if (f)
                {
                    cout << " Which Client  ? \n";
                    cout << "--------------------------\n";
                    for (int i = 0; i < Clsize; i++)
                    {
                        cout << i + 1 << ". ";
                        cl[i].DisplayID();
                    }
                    int m;
                    cout << "How many Do You Want To Add ? ";
                    cin >> m;
                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        a.AddClients(&cl[f - 1]);
                        cout << "Client Has Been Added Successfully!\n";
                    }
                }
            }
            else
                cout << "There is No Clients To Add !\n";
            ag.Insert(a);
            agcount++;
            t = true;
        }
        if (t)
            cout << "Clients Added Succesfully !\n";
        else
            cout << "Error Adding Clients \n";
    }
    void add_probertie_to_Ag()
    {
        if (Psize > 0)
        {
            if (agcount == 0)
            {
                cout << "There is No Agents To Add Proberites to !\n";
                return;
            }
            cout << "Choose The Agent You Want to Add Client To : \n";
            ag.printTree(ag.getroot(), "", true);
            string id;
            cout << "\nEnter The Needed Agent ID As You See It : \n";
            cin >> id;
            agent a(id);
            auto *l = ag.Search(ag.hash(a), ag.getroot());
            auto *agl = l->searchByValue(a);
            if (l)
            {
                cout << "Which Proberity?\n";
                for (int i = 0; i < Psize; i++)
                {
                    cout << i + 1 << ". ";
                    prop[i].DisplayID();
                }
                int m;
                cout << "How many Do You Want To Add ? ";
                cin >> m;
                int f;
                if (l->data == a)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        l->data.AddProberity(&prop[f - 1]);
                        cout << "Proberity Has Been Added Successfully!\n";
                    }
                }

                else if (agl->data == a)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        agl->data.AddProberity(&prop[f - 1]);
                        cout << "Proberity Has Been Added Successfully!\n";
                    }
                }
            }
        }
        else
            cout << "No proberites To Add To Agents!\n";
    }
    void add_proberity_to_Cl()
    {
        if (Psize > 0)
        {
            if (Clsize == 0)
            {
                cout << "There is No Clients to Add Proberites For !\n";
            }
            int prinx, clinx;

            cout << "\t\tClients List :\n\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < Clsize; i++)
            {
                cout << i + 1 << ". ";
                cl[i].Display();
                cout << "-----------------------------------------------\n";
            }
            cout << endl;

            cout << "\t\tProberites List :\n\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < Psize; i++)
            {
                cout << i + 1 << ". ";
                prop[i].DisplayID();
                cout << "-----------------------------------------------\n";
            }
            cout << "Enter Client's Number & Proberite Number Please : ";
            cout << "\n CL no. : ";
            cin >> clinx;
            cout << "\n Pro no. : ";
            cin >> prinx;

            cl[clinx - 1].AddActivity(&prop[prinx - 1]);
            cout << "Proberite Has Been Added Successfully!";
        }
        else
            cout << "There is No Proberites to Add to the Client  !";
    }
    void add_Cl_to_AG()
    {
        if (Clsize > 0)
        {
            if (agcount == 0)
            {
                cout << "There is No Agents To Add Clients to !\n";
                return;
            }
            string id;
            cout << "Choose The Agent You Want to Add Client To : \n";
            ag.printTree(ag.getroot(), "", true);
            cout << "\nEnter The Needed Agent ID As You See It : \n";
            cin >> id;
            agent a(id);

            auto *l = ag.Search(ag.hash(a), ag.getroot());
            auto *agl = l->searchByValue(a);
            if (l)
            {
                cout << " Which Client ? \n";
                for (int i = 0; i < Clsize; i++)
                {
                    cout << i + 1 << ". ";
                    cl[i].DisplayID();
                }
                int m;
                cout << "How many Do You Want To Add ? ";
                cin >> m;
                int f;
                if (l->data == a)
                {
                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        l->data.AddClients(&cl[f - 1]);
                        cout << "Client Has Been Added Successfully!\n";
                    }
                }

                else if (agl->data == a)
                {

                    for (int j = 0; j < m; j++)
                    {
                        cout << "Enetr Selection : ";
                        cin >> f;
                        agl->data.AddClients(&cl[f - 1]);
                        cout << "Client Has Been Added Successfully!\n";
                    }
                }
            }
        }
        else
            cout << "There is No Clients to Add !\n";
    }
    void delete_prob()
    {
        if (Psize == 0)
        {
            cout << "NO Proberities EXIST!\n";
            return;
        }
        bool deleted = false;

        for (int i = 0; i < Psize; i++)
        {
            cout << i + 1 << ". ";
            prop[i].Display();
            cout << "\n------------------------------------------";
        }
        int delid;
        cout << "Enter Proberity's Number to Delete : ";
        cin >> delid;

        for (int i = 0; i < Psize; ++i)
        {
            if (i == delid - 1)
            {
                if (i == Psize - 1)
                {
                    Psize--;
                }
                else
                {
                    prop[i] = prop[Psize - 1];
                    Psize--;
                }
                deleted = true;
                break;
            }
        }
        if (deleted)
        {
            cout << "Proberity DELETED SUCCESSFULLY !\n";
        }
        else
        {
            cout << "NO Proberity EXIST!\n";
        }
    }
    void delete_client()
    {
        if (Clsize == 0)
        {
            cout << "NO Clients EXIST!\n";
            return;
        }
        bool deleted = false;

        for (int i = 0; i < Clsize; i++)
        {
            cout << i + 1 << ". ";
            cl[i].Display();
            cout << "\n------------------------------------------\n";
        }
        int delid;
        cout << "Enter Client's Number to Delete : ";
        cin >> delid;

        for (int i = 0; i < Clsize; ++i)
        {
            if (i == delid - 1)
            {
                if (i == Clsize - 1)
                {
                    Clsize--;
                }
                else
                {
                    cl[i] = cl[Clsize - 1];
                    Clsize--;
                }
                deleted = true;
                break;
            }
        }
        if (deleted)
        {
            cout << "Client DELETED SUCCESSFULLY !\n";
        }
        else
        {
            cout << "NO Client EXIST!\n";
        }
    }
    void delete_agent()
    {
        if (agcount > 0)
        {
            string id;
            cout << "Please Enter Agent ID To Delete : ";
            cin >> id;
            agent a(id);
            if (ag.deletenode(ag.getroot(), a))
                cout << "Agent Deleted SUCCESSFULLY !\n";
            else
                cout << "Theres Is No Agent With This ID !\n";
        }
        else
            cout << "No Agents To Delete!\n";
    }
    void Search_prob()
    {

        string id;
        bool t = false;
        if (Psize == 0)
            cout << "\nThere are No Proberites to search for ! \n";
        else
        {
            cout << "\nEnter Proberite ID to Find please..";
            cin >> id;
            for (int i = 0; i < Psize; i++)
            {
                if (prop[i].getuserid() == id)
                {
                    cout << "Proberite  NO." << i << endl;
                    cout << "\n-------------------------------------------------------------------------------\n";
                    prop[i].Display();
                    cout << "\n-------------------------------------------------------------------------------\n";
                    t = true;
                    break;
                }
            }
            if (!t)
                cout << "Proberity Not Found !";
        }
    }
    void Search_client()
    {
        string id;
        bool t = false;
        if (Clsize == 0)
            cout << "\nThere are No Clients to search for ! \n";
        else
        {
            cout << "\nEnter Client ID to Find please..";
            cin >> id;
            for (int i = 0; i < Clsize; i++)
            {
                if (cl[i].getclientid() == id)
                {
                    cout << "Client  NO." << i << endl;
                    cout << "\n-------------------------------------------------------------------------------\n";
                    cl[i].Display();
                    cout << "\n-------------------------------------------------------------------------------\n";
                    t = true;
                    break;
                }
            }
            if (!t)
                cout << "Client Not Found !\n";
        }
    }
    void Search_agent()
    {
        if (agcount > 0)
        {
            string id;
            cout << "Please Enter Agent ID To Search for : ";
            cin >> id;
            agent a(id);
            auto *l = ag.Search(ag.hash(a), ag.getroot());
            if (l)
            {
                cout << "Agent Found : \n";
                if (l->data == a)
                {
                    l->data.Display();
                }

                else
                {

                    auto *agl = l->searchByValue(a);
                    if (agl)
                        agl->data.Display();
                }
            }
            else
                cout << "Theres Is No Agent With This ID !\n";
        }
        else
            cout << "No Agents To Search for !\n";
    }
    void deletefrom_agent()
    {
        string id;
        cout << "Please Enter Agent ID To Search for : ";
        cin >> id;
        agent a(id);
        auto *l = ag.Search(ag.hash(a), ag.getroot());
        if (l)
        {
            int f;
            cout << "Do You Want To Delete [1.Client , 2.Proberity] :\n";
            cin >> f;
            if (f == 1)
            {
                cout << "Enter Client's ID : ";
                cin >> id;
                client c(id);
                if (l->data == a)
                {
                    l->data.delete_client(c);
                }

                else
                {

                    auto *agl = l->searchByValue(a);
                    agl->data.delete_client(c);
                }
            }
            else
            {
                cout << "Enter Proberity's ID : ";
                cin >> id;
                realestate r(id);
                if (l->data == a)
                {
                    l->data.delete_prob(r);
                }

                else
                {

                    auto *agl = l->searchByValue(a);
                    agl->data.delete_prob(r);
                }
            }
        }
        else
            cout << "Theres Is No Agent With This ID !\n";
    }
    void DisplayAgents()
    {
        if (agcount > 0)
            ag.printTree(ag.getroot(), "", true);
        else
            cout << "No Agents To Display !\n";
    }
    void Display_clients()
    {
        if (Clsize > 0)
        {
            for (int i = 0; i < Clsize; i++)
            {
                cout << i + 1 << ". ";
                cl[i].Display();
            }
        }
        else
            cout << "No Clients To Display !\n";
    }
    void Display_probrtites()
    {
        if (Psize > 0)
        {
            for (int i = 0; i < Psize; i++)
            {
                cout << i + 1 << ". ";
                prop[i].Display();
            }
        }
        else
            cout << "No Proberites To Display!\n";
    }
    ~RealEstateAgency() {}
};

#endif
// void add_probertie_to_Ag()
// {
//     if (Psize > 0)
//     {
//         if (agcount == 0)
//         {
//             cout << "There is No Agents To Add Proberites to !\n";
//             return;
//         }
//         cout << "Choose The Agent You Want to Add Client To : \n";
//         ag.printTree(ag.getroot(), "", true);
//         string id;
//         cout << "\n Enter The Needed Agent ID As You See It : \n";
//         cin >> id;
//         agent a(id);
//         auto *l = ag.Search(ag.hash(a), ag.getroot());
//         auto *agl = l->searchByValue(a);
//         if (l)
//         {
//             if (l->data == a)
//             {
//                 a = l->data;
//             }

//             else
//             {
//                 a = agl->data;
//             }
//             cout << " Which Proberity  ? ";
//             for (int i = 0; i < Psize; i++)
//             {
//                 cout << i + 1 << ". ";
//                 prop[i].DisplayID();
//                             }
//             int m;
//             cout << "How many Do You Want To Add ? ";
//             cin >> m;
//             int f;
//             for (int j = 0; j < m; j++)
//             {
//                 cout << "Enetr Selection : ";
//                 cin >> f;
//                 a.AddProberity(&prop[f - 1]);
//                 cout << "Proberity Has Been Added Successfully!\n";
//             }
//             if (l->data == a)
//                 l->data = a;
//             else if (agl->data == a)
//                 agl->data = a;
//         }
//     }
//     else
//     cout<<"No proberites To Add To Agents!\n";
// }