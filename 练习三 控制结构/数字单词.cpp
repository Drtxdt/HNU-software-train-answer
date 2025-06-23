#include <iostream>
using namespace std;

char ch;

int main()
{
    cin >> ch;
    if (ch == '0')
        cout << "Zero" << endl;
    else if (ch == '1')
        cout << "One" << endl;
    else if (ch == '2')
        cout << "Two" << endl;
    else if (ch == '3')
        cout << "Three" << endl;
    else if (ch == '4')
        cout << "Four" << endl;
    else if (ch == '5')
        cout << "Five" << endl;
    else if (ch == '6')
        cout << "Six" << endl;
    else if (ch == '7')
        cout << "Seven" << endl;
    else if (ch == '8')
        cout << "Eight" << endl;
    else if (ch == '9')
        cout << "Nine" << endl;
    else
        cout << "Other" << endl;
    return 0;
}