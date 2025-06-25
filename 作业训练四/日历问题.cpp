#include <iostream>
#include <iomanip>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    int days;
    string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    while (cin >> days && days != -1)
    {

        int dayOfWeek = (days + 6) % 7;

        int year = 2000;
        int curDays = days;

        while (curDays >= (isLeapYear(year) ? 366 : 365))
        {
            curDays -= (isLeapYear(year) ? 366 : 365);
            year++;
        }
        int months[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = 1;
        int day = 1;

        // 计算月份和日期
        for (int i : months)
        {
            if (curDays >= i)
            {
                curDays -= i;
                month++;
            }
            else
            {
                day += curDays;
                break;
            }
        }

        cout << year << "-"
            << setw(2) << setfill('0') << month << "-"
            << setw(2) << setfill('0') << day << " "
            << weekdays[dayOfWeek] << endl;
    }

    return 0;
}