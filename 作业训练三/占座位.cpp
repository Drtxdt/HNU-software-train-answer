#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool allocate_seats(vector<int>& seats, vector<vector<int>>& person_seats, int id, int num, int total_seats)
{
    int consecutive_count = 0;
    int current_start = 0;
    for (int i = 0; i < total_seats; i++)
    {
        if (seats[i] == -1)
        {
            if (consecutive_count == 0)
                current_start = i;
            
            consecutive_count++;
            if (consecutive_count >= num)
            {
                for (int j = current_start; j < current_start + num; j++)
                {
                    seats[j] = id;
                    person_seats[id].push_back(j);
                }
                return true;
            }
        }
        else
            consecutive_count = 0;
        
    }
    return false;
}

int main()
{
    int n, m, k;
    while (cin >> n)
    {
        cin >> m;
        cin >> k;
        int total_seats = n * n;
        vector<int> seats(total_seats, -1);
        vector<vector<int>> person_seats(m);

        for (int i = 0; i < k; i++)
        {
            string op;
            cin >> op;
            if (op == "in")
            {
                int id, num;
                cin >> id >> num;
                if (!person_seats[id].empty())
                {
                    cout << "no" << endl;
                }
                else
                {
                    if (allocate_seats(seats, person_seats, id, num, total_seats))
                        cout << "yes" << endl;
                    else
                        cout << "no" << endl;
                }
            }
            else if (op == "out")
            {
                int id;
                cin >> id;
                if (person_seats[id].empty())
                    cout << "no" << endl;
                else
                {
                    for (int seat : person_seats[id])
                        seats[seat] = -1;
                    person_seats[id].clear();
                    cout << "yes" << endl;
                }
            }
        }
    }
    return 0;
}