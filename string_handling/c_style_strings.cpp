#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    char name[] = "Ethan";
    /* E  t  h  a  n  \0 >> \0 is the null terminator (indicates the end of the string)
       0  1  2  3  4  5*/


    char source[] = "Hello, world!";
    char destination[30];

    strcpy(destination, source); // copies the string + \0 into destination

    cout << destination << endl;


    char first[20] = "Cow goes";
    char second[] = "moo!";

    strcat(first, second); // to the first, add the second... as above it copies the \0 too
    // so its Cow goes (finds the \0 and starts copying from there) + moo!\0
    //

    char sentence[] = "Car go vroooom";
    char word[] = "go";

    if(strstr(sentence, word) != nullptr) // searches for word inside sentence
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }




    
}