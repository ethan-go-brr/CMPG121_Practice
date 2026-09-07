#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct User
{
    string name;
    string studentNo;
    char equipmentType;
    bool checkedOut;

};

int findByStudentNo(User users[], int numOfUsers, string studentNo)
{
    int index;
    bool found = false;

    for (int i = 0; i < numOfUsers; i++)
    {
        if (users[i].studentNo == studentNo)
        {
            found = true;
            index = i;
        }
        else
        {
            continue;
        }
    }

    if (found)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

int registerUser(User users[], int& numOfUsers, string name, string studentNo, char equipment)
{
    if (numOfUsers == 20)
    {
        return -1;
    }

    if (findByStudentNo(users, numOfUsers, studentNo) != -1)
    {
        return -1;
    }

    users[numOfUsers].name = name;
    users[numOfUsers].studentNo = studentNo;
    users[numOfUsers].checkedOut = false;
    users[numOfUsers].equipmentType = equipment;
    numOfUsers++;
    return numOfUsers;

}

void listAll(User users[], int numOfUsers)
{
    if(numOfUsers == 0)
    {
        cout << "No users registered" << endl;
        return;
    }
    cout << left
    << setw(3) << "#"
    << setw(9) << "StudentNo"
    << setw(10) << "Name"
    << setw(12) << "Equipment"
    << setw(5) << "CheckedOut" << endl;

    string type, checked;

    for (int i = 0; i < numOfUsers; i++)
    {
        if(users[i].equipmentType == 'L')
        {
            type = "Laptop";
        }
        else
        {
            type = "Tablet";
        }

        if (users[i].checkedOut)
        {
            checked = "Yes";
        }
        else
        {
            checked = "No"; 
        }

        cout << left
        << setw(3) << i + 1
        << setw(9) << users[i].studentNo
        << setw(10) << users[i].name
        << setw(12) << type
        << setw(5) << checked << endl;
    }

}

bool checkOut(User users[], int numOfUsers, string studentNo)
{
    int index;
    index = findByStudentNo(users, numOfUsers, studentNo);

    if (index == -1)
    {
        return false;
    }
    else if (users[index].checkedOut)
    {
        return false;
    }
    else
    {
        users[index].checkedOut = true;
    }
    return true;
}

string toLowerCopy(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}

void searchByName(User users[], int numOfUsers, string search)
{
    if (numOfUsers == 0)
    {
        cout << "No users to search" << endl;
        return;
    }

    string searchLow, type, checked, nameLow;
    bool found = false;

    searchLow = toLowerCopy(search);

    cout << "Matches:" << endl;
    for (int i = 0; i < numOfUsers; i++)
    {
        nameLow = toLowerCopy(users[i].name);
        if(nameLow.find(searchLow) != -1)
        {
            found = true;

            if (users[i].equipmentType == 'L')
            {
                type = "Laptop";
            }
            else
            {
                type = "Tablet";
            }

            if (users[i].checkedOut)
            {
                checked = "Yes";
            }
            else
            {
                checked = "No";
            }

            cout << users[i].studentNo << " | " << users[i].name << " | " << type << " | " << checked << endl;
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

int removeUser(User users[], int& numOfUsers, string studentNo)
{
    int index;
    if (findByStudentNo(users, numOfUsers, studentNo) == -1)
    {
        return -1;
    }
    else
    {
        index = findByStudentNo(users, numOfUsers, studentNo);
    }

    for (int i = index; i < numOfUsers; i++)
    {
        users[i].name = users[i + 1].name;
        users[i].studentNo = users[i + 1].studentNo;
        users[i].checkedOut = users[i + 1].checkedOut;
        users[i].equipmentType = users[i + 1].equipmentType;
    }

    return numOfUsers--;
}

void summaryReport(User users[], int numOfUsers)
{
    int checked = 0, not_checked = 0, laptop = 0, tablet = 0;
    for (int i = 0; i < numOfUsers; i++)
    {
        if (users[i].checkedOut)
        {
            checked++;
        }
        else
        {
            not_checked++;
        }
        if (users[i].equipmentType == 'L')
        {
            laptop++;
        }
        else
        {
            tablet++;
        }
    }

    cout << "SUMMARY" << endl;
    cout << "Total registered: " << numOfUsers << " / 20" << endl;
    cout << "Remaining spaces: " << 20 - numOfUsers << endl;
    cout << "Laptops: " << laptop << endl;
    cout << "Tablets: " << tablet << endl;
    cout << "Checked-out: " << checked << endl;
    cout << "Not checked-out: " << not_checked << endl;

}
void showMenu(User users[], int& numOfUsers)
{
    int option;

    do
    {
        cout << "===== Campus Equipment Manager =====" << endl;
        cout << "1. Register user" << endl;
        cout << "2. List all users" << endl;
        cout << "3. Check-out equipment" << endl;
        cout << "4. Search users by name" << endl;
        cout << "5. Remove user" << endl;
        cout << "6. Summary report" << endl;
        cout << "0. Exit" << endl;
        cout << "Select option: ";
        cin >> option;

        if (option == 0)
        {
            cout << "Goodbye!" << endl;
            return;
        }

        switch(option)
        {
            case 1:
            {
                string studentNo;
                cout << "Enter student number (exactly 8 digits): ";
                cin >> studentNo;

                while (studentNo.length() != 8)
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid. Student number must be exactly 8 digits. Try again: ";
                    cin >> studentNo;
                }

                string name;
                cout << "Enter name: ";
                cin >> name;

                char type;
                cout << "Equipment type (L/T): ";
                cin >> type;

                while (type != 'L' && type != 'T')
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid equipment type. Enter L or T." << endl;
                    cout << "Equipment type (L/T): ";
                    cin >> type;
                }

                string equipType;
                if (type == 'L')
                {
                    equipType = "Laptop";
                }
                else
                {
                    equipType = "Tablet";
                }

                if (registerUser(users, numOfUsers, name, studentNo, type) != -1)
                {
                    cout << "Registered successfully for " << name << " (" << equipType << ") " << endl;
                }
                else
                {
                    cout << "Registration failed (duplicate ID or full capacity)." << endl;
                }
                break;
            }
            case 2:
            {
                listAll(users, numOfUsers);
                break;
            }
            case 3:
            {
                string studentNo;

                cout << "Enter student number to check-out: ";
                cin >> studentNo;
                if(checkOut(users, numOfUsers, studentNo))
                {
                    cout << "Check-out successful." << endl;
                }
                else
                {
                    cout << "Check-out failed (not found or already checked-out)." << endl;
                }

                break;
            }
            case 4:
            {
                string search;
                cout << "Enter part of name to search: ";
                cin >> search;
                searchByName(users, numOfUsers, search);
                break;
            }
            case 5:
            {
                string studentNo;

                cout << "Enter student number to remove: ";
                cin >> studentNo;

                if(removeUser(users, numOfUsers, studentNo) == -1)
                {
                    cout << "User not found." << endl;
                }
                else
                {
                    cout << "Removed successfully." << endl;
                }
                break;
            }
            case 6:
            {
                summaryReport(users, numOfUsers);
                break;
            }
            default:
            {
                cout << "Invalid input." << endl;
                break;
            }
        }


    } while (option != 0);
    
}

int main()
{
    User users[20];
    int numOfUsers = 0;
    showMenu(users, numOfUsers);
}

// completed in 1:38:05.72