#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <cstring>
#include <unordered_map>
using namespace std;

struct Student {
    string name;
    int age;
    int worth;
};

bool cmp(const Student& a, const Student& b) {
    if (a.worth != b.worth) {
        return a.worth > b.worth;
    }
    else {
        if (a.age != b.age) {
            return a.age < b.age;
        }
        return a.name < b.name;
    }
}

int cnts[201];

int main()
{
    memset(cnts, 0, sizeof(cnts));
    int n, k;
    cin >> n >> k;
    vector<Student> v, vp;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        string name;
        int age, worth;
        cin >> name >> age >> worth;
        vp.push_back({name, age, worth});
    }
    sort(vp.begin(), vp.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if (cnts[vp[i].age] < 100) {
            v.push_back(vp[i]);
            ++cnts[vp[i].age];
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << "Case #" << i + 1 << ':' << endl;
        int ns, l, r;
        cin >> ns >> l >> r;
        vector<Student> filtered;
        for (auto& s : v) {
            if (filtered.size() >= ns) break;
            if (s.age >= l && s.age <= r) {
                filtered.push_back(s);
            }
        }
        if (filtered.empty()) {
            cout << "None" << endl;
        }
        else {
            auto maxi = min(static_cast<int>(filtered.size()), ns);
            for (int i = 0; i < maxi; ++i) {
                cout << filtered[i].name << ' ' << filtered[i].age << ' ' << filtered[i].worth << endl;
            }
        }
    }

    return 0;
}
