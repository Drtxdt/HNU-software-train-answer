#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string current = "http://www.game.org/";
    stack<string> back_stack;
    stack<string> forward_stack;

    string op;
    while (cin >> op)
    {
        if (op == "VISIT")
        {
            string url;
            cin >> url;
            back_stack.push(current);
            current = url;
            while (!forward_stack.empty())
                forward_stack.pop();
            cout << current << endl;
        }
        else if (op == "BACK")
        {
            if (back_stack.empty())
                cout << "Ignored" << endl;
            else
            {
                forward_stack.push(current);
                current = back_stack.top();
                back_stack.pop();
                cout << current << endl;
            }
        }
        else if (op == "FORWARD")
        {
            if (forward_stack.empty())
                cout << "Ignored" << endl;
            else
            {
                back_stack.push(current);
                current = forward_stack.top();
                forward_stack.pop();
                cout << current << endl;
            }
        }
        else if (op == "QUIT")
            break;

    }
    return 0;
}