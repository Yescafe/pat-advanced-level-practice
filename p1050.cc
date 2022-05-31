#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    set<char> r;
    for (auto& c : s2) {
        r.insert(c);
    }

    for (auto& c : s1) {
        if (r.find(c) != r.end()) {
            continue;
        }
        cout << c;
    }

    return 0;
}
