#include <iostream>
using namespace std;
typedef long long ll;
constexpr int N = 5010;

int n;
int a[N];
int tmp[N];

ll merge_sort(int left, int right)
{
    if (left >= right) return 0;

    int mid = (left + right) >> 1;
    ll res = merge_sort(left, mid) + merge_sort(mid + 1, right);
    int cur1 = left, cur2 = mid + 1, i = left;
    while (cur1 <= mid && cur2 <= right)
    {
        if (a[cur1] <= a[cur2])
            tmp[i++] = a[cur1++];

        else
        {
            res += mid - cur1 + 1;
            tmp[i++] = a[cur2++];
        }
    }

    while (cur1 <= mid) tmp[i++] = a[cur1++];
    while (cur2 <= right) tmp[i++] = a[cur2++];

    for (int j = left; j <= right; j++)
        a[j] = tmp[j];
    return res;
}

int main()
{
    while (cin >> n && n != 0)
    {

        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long inverse_count = merge_sort(0, n - 1);
        cout << inverse_count << endl;
    }
    return 0;
}