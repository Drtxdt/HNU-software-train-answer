#include <iostream>
using namespace std;

constexpr int N = 2000;
int d[N], cnt;


int getSum(int x)
{
    if (x <= 1)
        return 0;

    cnt = 0;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            d[++cnt] = i;
            if (i != x / i)
                d[++cnt] = x / i;
        }
    }


    int sum = 0;
    for (int i = 1; i <= cnt; i++)
        sum += d[i];

    return sum - x;
}

int main()
{
    int A, B;
    while (cin >> A >> B)
    {

        int sumA = getSum(A);
        int sumB = getSum(B);

        if (sumA == B && sumB == A)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}