#include <iostream>
#include <algorithm>
using namespace std;
constexpr int N = 1e5 + 10;

int n;

struct node
{
    string name;
    string id;
    int grade;

    bool operator<(const node& rhs) const
    {
        return grade < rhs.grade;
    }
}a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].name >> a[i].id >> a[i].grade;
    sort(a + 1, a + n + 1);
    cout << a[n].name << " " << a[n].id << endl;
    cout << a[1].name << " " << a[1].id << endl;
    return 0;
}