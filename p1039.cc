#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

unordered_map<string, set<int>> um;

int main()
{
    int qn, k;
    cin >> qn >> k;
    for (int i = 0; i < k; ++i) {
        int id, n;
        cin >> id >> n;
        for (int j = 0; j < n; ++j) {
            string stu;
            cin >> stu;
            auto fnd = um.find(stu);
            if (fnd != um.end()) {
                fnd->second.insert(id);
            }
            else {
                um[stu] = {};
                um[stu].insert(id);
            }
        }
    }

    for (int i = 0; i < qn; ++i) {
        string name;
        cin >> name;
        auto& s = um[name];
        cout << name << " " << s.size();
        for (auto& item : s) {
            cout << " " << item;
        }
        cout << endl;
    }

    return 0;
}
