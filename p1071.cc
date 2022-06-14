#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);

    string word;
    unordered_map<string, int> m;
    for (auto& ch : sentence) {
        if (isalnum(ch)) {
            word += tolower(ch);
        }
        else if (!word.empty()) {
            ++m[word];
            word.clear();
        }
    }
    if (!word.empty()) {
        ++m[word];
    }

    pair<string, int> ans({}, -1);
    for (auto& p : m) {
        if (ans.second < p.second) {
            ans = p;
        }
        else if (ans.second == p.second) {
            if (ans.first > p.first) {
                ans = p;
            }
        }
    }

    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}

