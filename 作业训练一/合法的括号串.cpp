#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        bool valid = true;

        for (char c : s)
        {

            if (c == '(' || c == '{' || c == '[' || c == '<')
                st.push(c);
            else if (!st.empty())
            {
                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[') ||
                    (c == '>' && top == '<'))
                {
                    st.pop();
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            else
            {
                valid = false;
                break;
            }
        }

        if (!st.empty()) valid = false;
        cout << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}