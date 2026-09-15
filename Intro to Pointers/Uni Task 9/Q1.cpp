// 56416563
// Ethan Govender

#include <iostream>

using namespace std;

int main()
{

    int val = 10;
    int *ptr = &val;

    cout << "Value of a: " << val << endl;
    cout << "Value of a using a pointer: " << *ptr << endl;
    cout << "Address of a: " << &val << endl;
    cout << "Address stored in pointer p: " << ptr << endl;

    *ptr = 20;

    cout << "After modifying the value of a through pointer p: " << endl;
    cout << "Value of a: " << *ptr << endl;
}
