// 56416563
// Ethan Govender

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int arr[5];
    int *ptr = arr;

    int highest;
    int total = 0;
    double average;


    cout << "Enter 5 integers: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + i) << " ";
    }
    
    cout << endl;
    
    highest = *ptr;

    for (int i = 0; i < 5; i++)
    {
        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
        }
        total += *(ptr + i);
    }

    average = static_cast<double>(total) / 5;

    cout << "Highest value in the array: " << highest << endl;
    cout << "Total of all elements: " << total << endl;
    cout << fixed << setprecision(2);
    cout << "Average of elements: " << average << endl;
}