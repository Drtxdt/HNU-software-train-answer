#include <iostream>
using namespace std;

int main()
{
    int p_galleon, p_sickle, p_knut;
    int a_galleon, a_sickle, a_knut;
    scanf("%d.%d.%d", &p_galleon, &p_sickle, &p_knut);
    scanf("%d.%d.%d", &a_galleon, &a_sickle, &a_knut);
    int p = p_galleon * 17 * 29 + p_sickle * 29 + p_knut;
    int a = a_galleon * 17 * 29 + a_sickle * 29 + a_knut;
    int t = a - p;
    if (t < 0)
    {
        cout << "-";
        t = -t;
    }
    int t_galleon = t / (17 * 29);
    t %= 17 * 29;
    int t_sickle = t / 29;
    t %= 29;
    printf("%d.%d.%d", t_galleon, t_sickle, t);
    return 0;
}