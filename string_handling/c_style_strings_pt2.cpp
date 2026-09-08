#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;


struct Contact
{
    char name[50];
    char phone[20];
};

void addContact(Contact ct[], int& count)
{
    if (count == 10)
    {
        cout << "List is full" << endl;
    }

    cout << "Enter name: ";
    cin.getline(ct[count].name, 50);

    cout << "Enter phone number: ";
    cin.getline(ct[count].phone, 20);

    cout << "Contact added succesfully" << endl;
    count++;

}

void toLowerCopy(char str[])
{
    for(int i = 0; str[i] != '/0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void searchContacts(Contact ct[], int count)
{
    if (count == 0)
    {
        cout << "No contacts to search" << endl;
        return;
    }

    char str[50];
    char tempName[50];
    bool found = false;
    cout << "Enter search term: ";
    cin.getline(str, 50);

    toLowerCopy(str);
    
    cout << "Matches:" << endl;
    for (int i = 0; i < count; i++)
    {
        strcpy(tempName, ct[i].name);
        if (strstr(tempName, str) != nullptr)
        {
            found = true;
            cout << "Name: " << ct[i].name << endl;
            cout << "Phone number: " << ct[i].phone << endl;
        }
        else
        {
            continue;
        }
    }

    if (!found)
    {
        cout << "No matches found" << endl;
    }
}

void deleteContact(Contact ct[], int& count)
{
    if (count == 0)
    {
        cout << "No contacts to delete" << endl;
        return;
    }

    char str[50];
    bool found = false;
    int index = 0;

    cout << "Enter name to delete: ";
    cin.getline(str, 50);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(ct[i].name, str) == 0)
        {
            found = true;
            index = i;
        }
        else
        {
            continue;
        }
    }

    if (!found)
    {
        cout << "Name not found" << endl;
        return;
    }

    for (int i = index; i < count - 1; i ++)
    {
        strcpy(ct[i].name, ct[i + 1].name);
        strcpy(ct[i].phone, ct[i + 1].phone);
    }
    count--;
    cout << "Contact deleted successfully" << endl;

}

void displayContacts(Contact ct[], int count)
{
    if (count == 0)
    {
        cout << "The contact list is empty" << endl;
        return;
    }

    cout << "===== CONTACTS =====" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << i+1 << ". " << ct[i].name << endl;
        cout << right << setw(3) << "Phone: " << ct[i].phone << endl;
        cout << endl;
    }
}
int main()
{
    Contact ct[10];
    int numContact = 0;
    int option;

    do
    {
       cout << "===== CONTACT MANGER =====" << endl;
       cout << "1. Add contact" << endl;
       cout << "2. Search contacts" << endl;
       cout << "3. Delete contact" << endl;
       cout << "4. Display contacts" << endl;
       cout << "5. Exit" << endl;

       cout << "Select option: ";
       cin >> option;
       cin.ignore();

       switch (option)
       {
            case 1:
            {
                addContact(ct, numContact);
                break;
            }
            case 2:
            {
                searchContacts(ct, numContact);
                break;
            }
            case 3:
            {
                deleteContact(ct, numContact);
                break;
            }
            case 4:
            {
                displayContacts(ct, numContact);
                break;
            }
            case 5:
            {
                cout << "Goodbye!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid input" << endl;
                break;
            }
       }
    } while (option != 5);
    

}