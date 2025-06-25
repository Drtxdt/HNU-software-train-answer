//来源 通心粉丝 --Drtxdt注
#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;

int a[30];
int b[30];
int res[30];
int n;

void sour(int now_floor, int num_1, int sum)
{

    if (now_floor == n)
    {
        res[num_1] += sum;
        return;
    }

    sour(now_floor + 1, num_1, sum);
    sour(now_floor + 1, num_1 + 1, sum * a[now_floor]); //往右走，选择为1，sum+1，同时乘积改变
}

int main()
{
    while (cin >> n && n)
    {
        memset(res, 0, sizeof(res));

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sour(0, 0, 1);


        int flag = 1;
        for (int i = 0; i < n; i++)
        {
          
            if (res[i + 1] != b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag) cout << "Y" << endl;
        else cout << "N" << endl;
    }
}