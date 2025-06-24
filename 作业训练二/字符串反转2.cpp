#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        istringstream iss(line);
        vector<string> words;
        string word;

        while (iss >> word)
            words.push_back(word);
        reverse(words.begin(), words.end());
        string reversed;
        for (auto& w : words)
        {
            if (!reversed.empty())
                reversed += " ";
            reversed += w;
        }
        cout << reversed << endl;
    }
    return 0;
}