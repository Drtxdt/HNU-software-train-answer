#include <algorithm>
#include <iostream>
using namespace std;

constexpr int N = 3;
long long y[N];  // 使用long long防止大年份溢出
int m[N], d[N];

struct node {
    long long num;  // 使用long long存储日期数值
    char index;

    // 添加比较运算符，使sort知道如何比较node对象
    bool operator<(const node& other) const {
        return num < other.num;
    }
} a[N];

int main() {
    for (int i = 0; i < N; i++) {
        cin >> y[i] >> m[i] >> d[i];
        a[i].num = y[i] * 10000LL + m[i] * 100 + d[i];  // 添加LL后缀确保long long运算
        a[i].index = 'A' + i;  // 简化的标识符赋值
    }
    sort(a, a + N);
    for (int i = 0; i < N; i++)
        cout << a[i].index;
    return 0;
}