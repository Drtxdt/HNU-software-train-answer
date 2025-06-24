#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, string> spell_to_func;
    unordered_map<string, string> func_to_spell;

    string s;
    while (getline(cin, s))
    {
        if (s == "@END@")
            break;
        size_t pos = s.find(']');
        string spell = s.substr(1, pos - 1);
        string func = s.substr(pos + 2);

        spell_to_func[spell] = func;
        func_to_spell[func] = spell;
    }

    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string query;
        getline(cin, query);

        if (query[0] == '[' && query[query.size()-1] == ']')
        {
            string spell = query.substr(1, query.size()-2);  // 去除括号
            if (spell_to_func.count(spell))
                cout << spell_to_func[spell] << endl;
            else
                cout << "what?" << endl;
        }
        else
        {
            if (func_to_spell.count(query))
                cout << func_to_spell[query] << endl;
            else
                cout << "what?" << endl;
        }
    }

    return 0;
}