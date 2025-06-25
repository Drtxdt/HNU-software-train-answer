//原作者 通心粉丝 由 Drtxdt优化
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int ball_score(char a)
{
    switch (a)
    {
    case 'r': return 1;
    case 'y': return 2;
    case 'g': return 3;
    case 'c': return 4;
    case 'b': return 5;
    case 'p': return 6;
    case 'B': return 7;
    default: return 0;
    }
}

int ball[8];

int ball_num(char a)
{
    return ball[ball_score(a)];
}

void init_ball_num()
{
    ball[1] = 15;
    for (int i = 2; i <= 7; i++) ball[i] = 1;
}

int A_100_times = 0, B_100_times = 0;
int A_score, B_score;

void A_red();
void B_red();
void A_color(char fa);
void B_color(char fa);

int A_hit_score = 0, B_hit_score = 0;


void A_red()
{
    if (ball_num('r') == 0)
    {
        A_color('r');
        return;
    }

    if (B_hit_score >= 100)
    {
        B_100_times++;
        B_hit_score = 0;
    }

    string condition;
    getline(cin, condition);

    if (condition == "-1")
    {
        if (A_hit_score >= 100) A_100_times++;
        A_hit_score = 0;
        B_hit_score = 0;

        cout << A_score << ":" << B_score << endl;
        return;
    }

    if (condition == "NULL")
    {
        B_score += 4;
        B_hit_score = 0;
        B_red();
    }
    else if (condition.find(' ') != string::npos)
    {
        string hit = condition.substr(0, condition.find(' '));
        string drop = condition.substr(condition.find(' ') + 1, condition.size() - condition.find(' '));
        int flag1 = 1;
        int maxi1 = 4;
        for (char i : hit)
        {
            if (i != 'r') flag1 = 0;
            if (maxi1 < ball_score(i)) maxi1 = ball_score(i);
        }

        int flag2 = 1;
        int maxi2 = 4;
        for (char i : drop)
        {
            if (i != 'r')
            {
                if (i < '0' || i > '9')
                    flag2 = 0;
            }
            if (maxi2 < ball_score(i)) maxi2 = ball_score(i);
        }
        int r_num = 0;
        if (drop.find('r') != string::npos)
        {
            int pos = drop.find('r');
            vector<int> v;
            for (int i = pos + 1; i < drop.size(); i++)
            {
                if (drop[i] >= '0' && drop[i] <= '9') v.push_back(drop[i] - '0');
            }
            if (v.size() == 1)
            {
                r_num += v[0];
                ball[ball_score('r')] -= r_num;
            }
            else
            {
                r_num += v[0] * 10 + v[1];
                ball[ball_score('r')] -= r_num;
            }
        }

        if (flag1 == 0 || flag2 == 0)
        {
            B_score += max(maxi1, maxi2);
            B_hit_score = 0;
            B_red();
        }
        else
        {
            A_hit_score += r_num;
            A_score += r_num;
            A_color('f');
        }
    }
    else
    {
        int flag = 1;
        for (char i : condition)
        {
            if (i != 'r')
                flag = 0;

        }
        if (flag == 1)
        {
            B_hit_score = 0;
            B_red();
        }
        else
        {
            int maxi3 = 4;
            for (char i : condition)
                if (ball_score(i) > maxi3) maxi3 = ball_score(i);
            B_score += maxi3;
            B_hit_score = 0;
            B_red();
        }
    }
}

void A_color(char fa)
{
    if (B_hit_score >= 100)
    {
        B_100_times++;
        B_hit_score = 0;
    }

    string condition;
    getline(cin, condition);

    if (condition == "-1")
    {
        if (A_hit_score >= 100) A_100_times++;
        A_hit_score = 0;
        B_hit_score = 0;
        cout << A_score << ":" << B_score << endl;
        return;
    }

    if (fa == 'f')
    {
        if (condition == "NULL")
        {
            B_score += 4;
            B_hit_score = 0;
            B_red();
        }
        else if (condition.find(' ') != string::npos)
        {
            string hit = condition.substr(0, condition.find(' '));
            string drop = condition.substr(condition.find(' ') + 1, condition.size() - condition.find(' '));
            if (drop.find('r') != string::npos)
            {
                int r_num = 0;
                int pos = drop.find('r');
                vector<int> v;
                for (int i = pos + 1; i < drop.size(); i++)
                    if (drop[i] >= '0' && drop[i] <= '9') v.push_back(drop[i] - '0');
                if (v.size() == 1)
                {
                    r_num += v[0];
                    ball[ball_score('r')] -= r_num;
                }
                else
                {
                    r_num += v[0] * 10 + v[1];
                    ball[ball_score('r')] -= r_num;
                }
            }

            int flag1 = 1;
            int maxi1 = 4;
            if (hit == "r" || hit.size() > 1)
            {
                flag1 = 0;
                for (char i : hit)
                    if (ball_score(i) > maxi1) maxi1 = ball_score(i);

            }

            if (flag1 == 0)
            {

                for (char i : drop)
                    if (ball_score(i) > maxi1) maxi1 = ball_score(i);
                B_score += maxi1;
                B_hit_score = 0;
                B_red();
            }
            else
            {
                if (drop == hit)
                {
                    A_hit_score += ball_score(drop[0]);
                    A_score += ball_score(drop[0]);
                    A_red();
                }
                else
                {
                    int maxi3 = 4;
                    for (char i : hit)
                        if (ball_score(i) > maxi3) maxi3 = ball_score(i);
                    for (char i : drop)
                        if (ball_score(i) > maxi3) maxi3 = ball_score(i);
                    B_score += maxi3;
                    B_hit_score = 0;
                    B_red();
                }
            }
        }
        else
        {
            if (condition == "r" || condition.size() > 1)
            {
                int maxi = 4;
                for (char i : condition)
                    if (ball_score(i) > maxi) maxi = ball_score(i);
                B_score += maxi;
                B_hit_score = 0;
                B_red();
            }
            else
            {
                B_hit_score = 0;
                B_red();
            }
        }
    }
    else
    {
        string sub = "rygcbpB";
        string goal = sub.substr(sub.find(fa) + 1, 1);
        char c_goal = sub[sub.find(fa) + 1];

        if (condition == "NULL")
        {
            B_score += 4;
            B_hit_score = 0;
            B_color(fa);
        }
        else if (condition.find(' ') != string::npos)
        {
            string hit = condition.substr(0, condition.find(' '));
            string drop = condition.substr(condition.find(' ') + 1, condition.size() - condition.find(' '));

            if (hit == goal && hit == drop)
            {

                A_hit_score += ball_score(c_goal);
                A_score += ball_score(c_goal);
                ball[ball_score(c_goal)]--;
                A_color(c_goal);
            }
            else
            {

                int maxi3 = max(4, ball_score(c_goal));
                for (char i : hit)
                    if (ball_score(i) > maxi3) maxi3 = ball_score(i);
                for (char i : drop)
                    if (ball_score(i) > maxi3) maxi3 = ball_score(i);
                B_score += maxi3;
                B_hit_score = 0;
                B_color(fa);
            }
        }
        else
        {
            const string& hit = condition;
            if (hit == goal)
            {
                B_hit_score = 0;
                B_color(fa);
            }
            else
            {
                int maxi = 4;
                for (char i : hit)
                    if (ball_score(i) > maxi) maxi = ball_score(i);
                B_score += maxi;
                B_hit_score = 0;
                B_color(fa);
            }
        }
    }
}

void B_red()
{
    if (ball_num('r') == 0)
    {
        B_color('r');
        return;
    }

    if (A_hit_score >= 100)
    {
        A_100_times++;
        A_hit_score = 0;
    }

    string condition;
    getline(cin, condition);

    if (condition == "-1")
    {
        if (B_hit_score >= 100) B_100_times++;
        A_hit_score = 0;
        B_hit_score = 0;

        cout << A_score << ":" << B_score << endl;
        return;
    }

    if (condition == "NULL")
    {
        A_score += 4;
        A_hit_score = 0;
        A_red();
    }
    else if (condition.find(' ') != string::npos)
    {
        string hit = condition.substr(0, condition.find(' '));
        string drop = condition.substr(condition.find(' ') + 1, condition.size() - condition.find(' '));
        int flag1 = 1;
        int maxi1 = 4;
        for (char i : hit)
        {
            if (i != 'r') flag1 = 0;
            if (maxi1 < ball_score(i)) maxi1 = ball_score(i);
        }

        int flag2 = 1;
        int maxi2 = 4;
        for (char i : drop)
        {
            if (i != 'r')
                if (i < '0' || i > '9')
                    flag2 = 0;
            if (maxi2 < ball_score(i)) maxi2 = ball_score(i);
        }
        int r_num = 0;
        if (drop.find('r') != string::npos)
        {
            int pos = drop.find('r');
            vector<int> v;
            for (int i = pos + 1; i < drop.size(); i++)
                if (drop[i] >= '0' && drop[i] <= '9') v.push_back(drop[i] - '0');
            if (v.size() == 1)
            {
                r_num += v[0];
                ball[ball_score('r')] -= r_num;
            }
            else
            {
                r_num += v[0] * 10 + v[1];
                ball[ball_score('r')] -= r_num;
            }
        }

        if ((flag1 == 0 && flag2 == 0) ||flag1 == 0 || flag2 == 0)
        {
            A_score += max(maxi1, maxi2);
            A_hit_score = 0;
            A_red();
        }
        else
        {
            B_hit_score += r_num;
            B_score += r_num;
            B_color('f');
        }
    }
    else
    {
        int flag = 1;
        for (char i : condition)
        {
            if (i != 'r')
                flag = 0;
        }

        if (flag == 1)
        {
            A_hit_score = 0;
            A_red();
        }
        else
        {
            int maxi3 = 4;
            for (char i : condition)
                if (ball_score(i) > maxi3) maxi3 = ball_score(i);
            A_score += maxi3;
            A_hit_score = 0;
            A_red();
        }
    }
}

void B_color(char fa)
{
    if (A_hit_score >= 100)
    {
        A_100_times++;
        A_hit_score = 0;
    }

    string condition;
    getline(cin, condition);

    if (condition == "-1")
    {
        if (B_hit_score >= 100) B_100_times++;
        A_hit_score = 0;
        B_hit_score = 0;

        cout << A_score << ":" << B_score << endl;
        return;
    }

    if (fa == 'f')
    {
        if (condition == "NULL")
        {
            A_score += 4;
            A_hit_score = 0;
            A_red();
        }
        else if (condition.find(' ') != string::npos)
        {
            string hit = condition.substr(0, condition.find(' '));
            string drop = condition.substr(condition.find(' ') + 1, condition.size() - condition.find(' '));

            if (drop.find('r') != string::npos)
            {
                int r_num = 0;
                int pos = drop.find('r');
                vector<int> v;
                for (int i = pos + 1; i < drop.size(); i++)
                    if (drop[i] >= '0' && drop[i] <= '9') v.push_back(drop[i] - '0');
                if (v.size() == 1)
                {
                    r_num += v[0];
                    ball[ball_score('r')] -= r_num;
                }
                else
                {
                    r_num += v[0] * 10 + v[1];
                    ball[ball_score('r')] -= r_num;
                }
            }

            int flag1 = 1;
            int maxi1 = 4;
            if (hit == "r" || hit.size() > 1)
            {
                flag1 = 0;
                for (char i : hit)
                    if (ball_score(i) > maxi1) maxi1 = ball_score(i);
            }

            if (flag1 == 0)
            {
                for (char i : drop)
                    if (ball_score(i) > maxi1) maxi1 = ball_score(i);
                A_score += maxi1;
                A_hit_score = 0;
                A_red();
            }
            else
            {
                if (drop == hit)
                {
                    B_hit_score += ball_score(drop[0]);
                    B_score += ball_score(drop[0]);
                    B_red();
                }
                else
                {
                    int maxi3 = 4;
                    for (char i : hit)
                        if (ball_score(i) > maxi3) maxi3 = ball_score(i);
                    for (char i : drop)
                        if (ball_score(i) > maxi3) maxi3 = ball_score(i);
                    A_score += maxi3;
                    A_hit_score = 0;
                    A_red();
                }
            }
        }
        else
        {
            if (condition == "r" || condition.size() > 1)
            {
                int maxi = 4;
                for (char i : condition)
                    if (ball_score(i) > maxi) maxi = ball_score(i);
                A_score += maxi;
                A_hit_score = 0;
                A_red();
            }
            else
            {
                A_hit_score = 0;
                A_red();
            }
        }
    }
    else
    {
        string sub = "rygcbpB";
        string goal = sub.substr(sub.find(fa) + 1, 1);
        char c_goal = sub[sub.find(fa) + 1];

        if (condition == "NULL")
        {
            A_score += 4;
            A_hit_score = 0;
            A_color(fa);
        }
        else if (condition.find(' ') != string::npos)
        {
            string hit = condition.substr(0, condition.find(' '));
            string drop = condition.substr(condition.find(' ') + 1, condition.size() - condition.find(' '));

            if (hit == goal && hit == drop)
            {
                B_hit_score += ball_score(c_goal);
                B_score += ball_score(c_goal);
                ball[ball_score(c_goal)]--;
                B_color(c_goal);
            }
            else
            {

                int maxi = max(4, ball_score(c_goal));
                for (char i : hit)
                    if (ball_score(i) > maxi) maxi = ball_score(i);
                for (char i : drop)
                    if (ball_score(i) > maxi) maxi = ball_score(i);
                A_score += maxi;
                A_hit_score = 0;
                A_color(fa);
            }
        }
        else
        {
            const string& hit = condition;
            if (hit == goal)
            {
                A_hit_score = 0;
                A_color(fa);
            }
            else
            {
                int maxi = 4;
                for (char i : hit)
                    if (ball_score(i) > maxi) maxi = ball_score(i);
                A_score += maxi;
                A_hit_score = 0;
                A_color(fa);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    cin.get();
    while (t--)
    {
        A_score = 0;
        B_score = 0;
        A_hit_score = 0;
        B_hit_score = 0;
        init_ball_num();
        A_red();
    }
    cout << A_100_times << ":" << B_100_times;
}