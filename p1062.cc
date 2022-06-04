#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    string id;
    int virtue;
    int talent;
};

bool cmp(const Student& a, const Student& b) {
    auto a_total = a.virtue + a.talent;
    auto b_total = b.virtue + b.talent;
    if (a_total != b_total) {
        return a_total > b_total;
    }
    if (a.virtue != b.virtue) {
        return a.virtue > b.virtue;
    }
    if (a.talent != b.talent) {
        return a.talent > b.talent;
    }
    return a.id < b.id;
}

int main()
{
    int n, l, h;
    cin >> n >> l >> h;

    string id;
    int v, t;
    vector<Student> st[4];
    for (int i = 0; i < n; ++i) {
        cin >> id >> v >> t;
        if (v >= h && t >= h) {
            st[0].push_back({id, v, t});
        }
        else if (v >= h && t >= l) {
            st[1].push_back({id, v, t});
        }
        else if (v >= l && t >= l && v >= t) {
            st[2].push_back({id, v, t});
        }
        else if (v >= l && t >= l) {
            st[3].push_back({id, v, t});
        }
    }

    cout << st[0].size() + st[1].size() + st[2].size() + st[3].size() << endl;
    for (int i = 0; i < 4; ++i) {
        sort(st[i].begin(), st[i].end(), cmp);
        for (auto& s : st[i]) {
            cout << s.id << ' ' << s.virtue << ' ' << s.talent << endl;
        }
#ifndef ONLINE_JUDGE
        cout << endl;
#endif
    }

    return 0;
}
