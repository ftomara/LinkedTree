#include <iostream>
#include "RealEstateAgency.h"
using namespace std;

int main()
{
    int choice;
    RealEstateAgency r;
    // fstream file("/Users/fatmaomara/Desktop/C++/tasks/catalogbooks.txt");
    do
    {
        cout << "\t\t\033[1;38;2;120;70;150m-----------------------------------------------\n";
        cout << "\t\t|Welcome to My Humble RealEstate Agency System!|" << endl;
        cout << "\t\t-----------------------------------------------\n";
        cout << "Please select from the following options:" << endl;
        cout << "1. Display Agents" << endl;
        cout << "2. Display Clients" << endl;
        cout << "3. Display Proberites" << endl;
        cout << "4. Search for a Agent " << endl;
        cout << "5. Search for a Client" << endl;
        cout << "6. Search for a Proberity" << endl;
        cout << "7. Delete Agent" << endl;
        cout << "8. Delete Client" << endl;
        cout << "9. Delete Proberite" << endl;
        cout << "10. Add Agent" << endl;
        cout << "11. Add Client" << endl;
        cout << "12. Add Proberite" << endl;
        cout << "13. Add Proberite To Agent" << endl;
        cout << "14. Add Proberite To Client" << endl;
        cout << "15. Edit Agent[Delete,Add(Client , Proberity)]" << endl;
        cout << "16. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            r.DisplayAgents();
            break;
        case 2:
        {
            r.Display_clients();
            break;
        }
        break;
        case 3:
            r.Display_probrtites();
            break;
        case 4:
            r.Search_agent();
            break;
        case 5:
            r.Search_client();
            break;
        case 6:
            r.Search_prob();
            break;
        case 7:
            r.delete_agent();
            break;
        case 8:
            r.delete_client();
            break;
        case 9:
            r.delete_prob();
            break;
        case 10:
            r.addAgent();
            break;
        case 11:
            r.addClient();
            break;
        case 12:
            r.addProberity();
            break;
        case 13:
            r.add_probertie_to_Ag();
            break;
        case 14:
            r.add_proberity_to_Cl();
            break;
        case 15:
            int c, d;
            cout << "Do You Want To [1.Add] or [2.Delete] ? ";
            cin >> c;
            if (c == 1)
            {
                cout << "Add [1.proberity], [2.Client]? ";
                cin >> d;
                if (d == 1)
                {
                    r.add_probertie_to_Ag();
                }
                else
                    r.add_Cl_to_AG();
            }
            else
            {
                r.deletefrom_agent();
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 16);
    return 0;
}