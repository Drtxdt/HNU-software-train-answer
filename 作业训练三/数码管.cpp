#include <iostream>
#include <vector>
using namespace std;

// 定义0-9的数字笔画编码（低7位表示笔画）
const int segments[10] = {
    0x3F, // 0: 00111111
    0x06, // 1: 00000110
    0x5B, // 2: 01011011
    0x4F, // 3: 01001111
    0x66, // 4: 01100110
    0x6D, // 5: 01101101
    0x7D, // 6: 01111101
    0x07, // 7: 00000111
    0x7F, // 8: 01111111
    0x6F // 9: 01101111
};

int main()
{
    int first;
    while (cin >> first)
    {
        if (first == -1)
            break;

        vector<int> seq;
        seq.push_back(first);
        for (int i = 0; i < 9; i++)
        {
            int num;
            cin >> num;
            seq.push_back(num);
        }

        bool valid = true;
        for (int i = 0; i < 9; i++)
        {
            int a = seq[i], b = seq[i + 1];
            int seg_a = segments[a];
            int seg_b = segments[b];
            if (((seg_a & ~seg_b) == 0) || ((seg_b & ~seg_a) == 0))
            {

            }
            else
            {
                valid = false;
                break;
            }
        }

        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}