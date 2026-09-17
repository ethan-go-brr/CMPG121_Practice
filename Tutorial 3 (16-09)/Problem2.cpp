#include <iostream>

using namespace std;


void display(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {10, 20, 30};
    int *ptr = arr;
    int choice;

    do
    {
        cout << "1. Display" << endl;
        cout << "2. Change first number" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                display(arr, 3);
                break;
            }
            case 2:
            {
                int num;

                cout << "Enter new value: ";
                cin >> num;

                *ptr = num;

                break;
            }
            case 3:
            {
                cout << "Goodbye!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid menu option." << endl;
                break;
            }
        }
    } while (choice != 3);
    
}