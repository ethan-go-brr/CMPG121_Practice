// 56416563
// Ethan Govender

#include <iostream>

using namespace std;

int main()
{
    int val = 30;
    int &refVal = val;
    int *ptr = &val;

    cout << "Value of b: " << val << endl;
    cout << "Value of b using reference refB: " << refVal << endl;
    cout << "Value of b using pointer ptrB: " << *ptr << endl;

    refVal = 40;
    cout << "After modifying the value of b using reference refB: " << endl;
    cout << "Value of b: " << refVal << endl;

    *ptr = 50;
    cout << "After modifying the value of b using pointer ptrB: " << endl;
    cout << "Value of b: " << *ptr << endl;

    cout << "Address of b: " << &val << endl;
    cout << "Address stored in pointer ptrB: " << ptr << endl;
    cout << "Address of reference refB: " << &refVal << endl;
}