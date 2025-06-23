#include <iostream>

using namespace std;

int main()
{
    int y, one, two, three, four; //one    - 表示年份的个位     two    - 表示年份的十位    three - 表示年份的百位    four   - 表示年份的千位
    cin >> y;

    while (1)
    {
        y++;
        int x = y;
        // 以下语句求one、two、three、four
        four = x / 1000;
        x %= 1000;
        three = x / 100;
        x %= 100;
        two = x / 10;
        x %= 10;
        one = x;


        if (one == two || one == three || one == four || two == three || two == four || three == four) //判断数字是否重复
            continue; // 继续循环
        else
            break; // 终止循环
    }

    cout << y << endl;

    return 0;
}