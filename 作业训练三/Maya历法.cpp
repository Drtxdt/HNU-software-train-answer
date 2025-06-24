#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    const string haab_months[] = {
        "pop", "no", "zip", "zotz", "tzec", "xul",
        "yoxkin", "mol", "chen", "yax", "zac", "ceh",
        "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
    };

    const string tzolkin_names[] = {
        "imix", "ik", "akbal", "kan", "chicchan", "cimi",
        "manik", "lamat", "muluk", "ok", "chuen", "eb",
        "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
    };

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int day, year_haab;
        char month_str[20];
        scanf("%d.%s%d", &day, month_str, &year_haab);

        for (int j = 0; j < strlen(month_str); j++)
        {
            if (month_str[j] < 'a' || month_str[j] > 'z')
            {
                month_str[j] = '\0';
                break;
            }
        }

        int month_index = -1;
        for (int j = 0; j < 19; j++)
        {
            if (string(month_str) == haab_months[j])
            {
                month_index = j;
                break;
            }
        }

        long total_days = year_haab * 365L + month_index * 20L + day;
        int year_tzolkin = total_days / 260;
        int remainder = total_days % 260;

        int tzolkin_num = remainder % 13 + 1;
        int name_index = remainder % 20;

        cout << tzolkin_num << " " << tzolkin_names[name_index] << " " << year_tzolkin << endl;
    }

    return 0;
}