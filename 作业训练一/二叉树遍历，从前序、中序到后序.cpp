#include <iostream>
#include <string>
using namespace std;


string build_post(string& pre, string& in, int& pre_idx, int in_start, int in_end)
{
    if (in_start > in_end) return "";
    char root = pre[pre_idx];
    pre_idx++;
    int root_pos = in.find(root, in_start);
    for (int i = in_start; i <= in_end; ++i)
    {
        if (in[i] == root)
        {
            root_pos = i;
            break;
        }
    }
    string left = build_post(pre, in, pre_idx, in_start, root_pos - 1);
    string right = build_post(pre, in, pre_idx, root_pos + 1, in_end);
    return left + right + root;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string pre, in;
        cin >> pre >> in;
        int pre_idx = 0;
        string post = build_post(pre, in, pre_idx, 0, n - 1);
        cout << post << endl;
    }
    return 0;
}