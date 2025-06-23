#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long x, y;
    char c;
    long long ans[3] = {0};  // 初始化数组
    long long scores[3];     // 存储分数用于选择

    for (int i = 0; i < 3; i++) {
        cin >> x >> c >> y;  // 正确读取格式：整数 字符 整数

        // 计算月薪得分（整数除法）
        long long salary_score = (x / 5000) * 100;

        // 计算带薪假得分
        long long vacation_score = (c == 'y') ? 20 : 0;

        // 计算距离得分
        long long distance_score;
        if (y <= 2000) {
            distance_score = 100;
        } else {
            // 计算超过2000公里的部分（向上取整到200公里倍数）
            long long over = y - 2000;
            // 向上取整的除法：(over + 199) / 200
            long long deduct = (over + 199) / 200 * 10;
            distance_score = (deduct >= 100) ? 0 : (100 - deduct);
        }

        // 总得分
        scores[i] = salary_score + vacation_score + distance_score;
        ans[i] = scores[i];  // 存储分数
    }

    // 找出最高分
    long long max_score = max({scores[0], scores[1], scores[2]});

    // 按顺序选择（A/B/C优先级）
    if (scores[0] == max_score) {
        cout << 'A';
    } else if (scores[1] == max_score) {
        cout << 'B';
    } else {
        cout << 'C';
    }

    return 0;
}