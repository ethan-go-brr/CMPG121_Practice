#include <iostream>

using namespace std;


int findLargest(int *ptr, int size)
{
    int highest = *(ptr + 0);

    for (int i = 0; i < size; i++)
    {
        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
        }
    }

    return highest;
}

int main()
{
    int num[] = {25, 65, 89, 7, 45, 28};
    int *ptr = num;

    cout << "Array elements: ";
    for (int i = 0; i < 6; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    int highest = findLargest(num, 6);

    cout << "Largest number: " << highest << endl;
    return 0;
}