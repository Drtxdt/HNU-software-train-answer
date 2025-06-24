#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
using namespace std;

struct Paper
{
    string title;
    int citations{};
    int idx{};
    vector<string> words_lower;
};

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) break;
        vector<Paper> papers;
        string line;
        getline(cin, line);

        for (int i = 0; i < n; i++)
        {
            Paper paper;
            getline(cin, paper.title);
            cin >> paper.citations;
            getline(cin, line);
            paper.idx = i;
            stringstream title_stream(paper.title);
            string word;
            while (title_stream >> word)
            {
                string lower_word;
                for (char c : word)
                    lower_word += tolower(c);
                paper.words_lower.push_back(lower_word);
            }
            papers.push_back(paper);
        }

        int m;
        cin >> m;
        getline(cin, line);

        for (int i = 0; i < m; i++)
        {
            getline(cin, line);
            stringstream query_stream(line);
            string keyword;
            vector<string> query_terms;
            while (query_stream >> keyword)
            {
                string lower_keyword;
                for (char c : keyword)
                {
                    lower_keyword += tolower(c);
                }
                query_terms.push_back(lower_keyword);
            }
            map<string, int> keyword_count;
            for (const string& term : query_terms)
            {
                keyword_count[term]++;
            }
            vector<Paper> results;
            for (const Paper& p : papers)
            {
                map<string, int> paper_count;
                for (const string& word : p.words_lower)
                {
                    paper_count[word]++;
                }

                bool valid = true;
                for (const auto& kv : keyword_count)
                {
                    string term = kv.first;
                    int required = kv.second;
                    if (paper_count.find(term) == paper_count.end() || paper_count[term] < required)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    results.push_back(p);
                
            }
            sort(results.begin(), results.end(), [](const Paper& a, const Paper& b)
            {
                if (a.citations != b.citations)
                {
                    return a.citations > b.citations;
                }
                return a.idx < b.idx;
            });
            for (const Paper& p : results)
            {
                cout << p.title << endl;
            }
            cout << "***" << endl;
        }
        cout << "---" << endl;
    }
    return 0;
}