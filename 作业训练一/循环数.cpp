#include <iostream>
#include <string>
using namespace std;

string s;
int n;

string solution(const string& x, int k)
{
    string ans;
    int carry = 0;
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int d = x[i] - '0';
        int sum = d * k + carry;
        carry = sum / 10;
        int rem = sum % 10;
        ans = char(rem + '0') + ans;
    }
    if (carry)
        ans = to_string(carry) + ans;
    return ans;
}

int main()
{
    cin >> s;
    n = s.size();
    string t = s + s;
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        string x = solution(s, i);
        if (x.size() != n)
        {
            flag = false;
            break;
        }
        if (t.find(x) == string::npos)
        {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}