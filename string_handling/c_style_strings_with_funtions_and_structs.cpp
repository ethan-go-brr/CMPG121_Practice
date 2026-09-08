#include <iostream>
#include <cstring>

using namespace std;

struct Person
{
    char name[50];
};


void addName(Person people[], int& num)
{
    if (num == 10)
    {
        cout << "The list is full" << endl;
        return;
    }

    cout << "Enter a name: ";
    cin.getline(people[num].name,50);

    num++;
    cout << "Name added!" << endl;
}

void searchNames(Person people[], int& num)
{
    char str[50];
    bool found = false;
    cout << "Enter search term: ";
    cin.getline(str, 50);

    for (int i = 0; i < num; i++)
    {
        if(strstr(people[i].name, str) != nullptr)
        {
            found = true;
            cout << people[i].name << endl;
        }
        else
        {
            continue;
        }
    }

    if (!found)
    {
        cout << "No matches found" << endl;
        return;
    }
}

void deleteName(Person people[], int& num)
{
    char str[50];
    int index;
    bool found = false;

    cout << "Enter the exact name to delete: ";
    cin.getline(str,50);

    for (int i = 0; i < num; i++)
    {
        if(strcmp(people[i].name, str) == 0)
        {
            index = i;
            found = true;
            break;
        }
        else 
        {
            continue;
        }
    }

    if (found)
    {
        for (int i = index; i < num - 1; i++)
        {
            strcpy(people[i].name, people[i + 1].name);
        }
        num--;
    }
    else
    {
        cout << "Name was not found" << endl;
        return;
    }
}

void displayNames(Person people[], int& num)
{
    if (num == 0)
    {
        cout << "The list is empty" << endl;
        return;
    }

    for (int i = 0; i < num; i++)
    {
        cout << people[i].name << endl;
    }
}
int main()
{
    Person people[10];
    int option;
    int numPeople = 0;
    
    do
    {
        cout << "===== NAME MANAGER =====" << endl;
        cout << "1. Add name" << endl;
        cout << "2. Search names" << endl;
        cout << "3. Delete names" << endl;
        cout << "4. Display names" << endl;
        cout << "5. Exit" << endl;
        cout << "Select option: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
            case 1:
            {
                addName(people, numPeople);
                break;
            }
            case 2:
            {
                searchNames(people, numPeople);
                break;
            }
            case 3:
            {
                deleteName(people, numPeople);
                break;
            }
            case 4:
            {
                displayNames(people, numPeople);
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