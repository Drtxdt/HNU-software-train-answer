#include <iostream>
using namespace std;
typedef long long ll;
ll n;

string change(const char& x)
{
    if (x == '0')
        return "ling";
    if (x == '1')
        return "yi";
    if (x == '2')
        return "er";
    if (x == '3')
        return "san";
    if (x == '4')
        return "si";
    if (x == '5')
        return "wu";
    if (x == '6')
        return "liu";
    if (x == '7')
        return "qi";
    if (x == '8')
        return "ba";
    if (x == '9')
        return "jiu";
    return "";
}

int main()
{
    string s;
    cin >> s;
    for (const auto &c : s)
        n += c - '0';
    string t = to_string(n);
    for (const auto &c : t)
        cout << change(c) << " ";
    cout << endl;
    return 0;
}