#include <iostream>
using namespace std;

int a, b, c, d, e, f;
int x, y, z;

int main()
{
    scanf("%d:%d:%d %d:%d:%d", &a, &b, &c, &d, &e, &f);
    int m = a * 3600 + b * 60 + c;
    int n = d * 3600 + e * 60 + f;
    int ans = n - m;
    x = ans / 3600;
    ans %= 3600;
    y = ans / 60;
    ans %= 60;
    z = ans;
    printf("%d:%02d:%02d", x, y, z);
    return 0;
}