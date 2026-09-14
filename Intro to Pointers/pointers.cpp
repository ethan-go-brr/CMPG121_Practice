#include <iostream>

using namespace std;


void squareNumber(int *p)
{
    *p = (*p) * (*p);
}

int main()
{
    // & refers to the address of the variable in memory (address operator)
    // * dereference opertator (goes to the address and extracts the value stored there)

    // say you have:
    int x = 10; // x - value of 10
    int *p = &x; // declaration of a pointer (well the int *p is the dec) the &x is the address of x (p - address of x)
                 // p is a value that is stored at that address (in this case 10) 
    // pointers let you access and modify the original variable indirectly

    //eg

    int number = 25;
    int *ptr = &number; // points to the address of number

    cout << "Value: " << number << endl;
    cout << "Address: " << &number << endl;
    cout << "Value address: " << ptr << endl;
    cout << "Value through pointer: " << *ptr << endl;
    cout << "Pointer address: " << &ptr << endl;

    // &x gives the address of x
    // ptr stores that address (of x)
    // *ptr accesses the value stored at that address

    cout << endl;
    *ptr = 1000; // modifies the original variable (number) stored at that address
    cout << "Value: " << number << endl;
    cout << "Pointer value: " << *ptr << endl;


    int num;
    int choice;

    cout << "Enter a number: ";
    cin >> num;

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Display number\n";
        cout << "2. Calculate the square\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Number: " << num << endl;
                break;
            }
            case 2:
            {
                squareNumber(&num); // *p = &num
                cout << "Square nummber: " << num << endl;
                break;
            }
            case 3:
            {
                cout << "Goodbye!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid" << endl;
                break;
            }
        }
    } while (choice != 3);
    
    
    return 0;
}