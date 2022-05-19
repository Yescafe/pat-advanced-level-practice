#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct S {
    int c, m, e;
    double a;
    S() = default;
    S(int c, int m, int e, double a) : c(c), m(m), e(e), a(a) {}
};

unordered_map<char, int> proirity {{'A', 0}, {'C', 1}, {'M', 2}, {'E', 3}};

struct R {
    vector<pair<char, int>> v;
    R(S s) {
        v.push_back({'C', s.c});
        v.push_back({'M', s.m});
        v.push_back({'E', s.e});
        v.push_back({'A', s.a});
    }
    void printRank() {
        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
                    if (a.second != b.second) {
                        return a.second < b.second;
                    }
                    else {
                        return proirity[a.first] < proirity[b.first];
                    }
                });
        cout << v[0].second << " " << v[0].first << endl;
    }
};

using P = pair<string, S>;
vector<P> scores;
unordered_map<string, S> ranks;

int main()
{
    int n, k;
    cin >> n >> k;
    string id;
    int c, m, e;
    for (int i = 0; i < n; ++i) {
        cin >> id >> c >> m >> e;
        double a = (c + m + e) / 3.;
        scores.push_back(make_pair(id, S(c, m, e, a)));
    }

    sort(scores.begin(), scores.end(), [](const P& a, const P& b) {
                return a.second.c > b.second.c;
            });
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (scores[i].second.c == scores[i - 1].second.c) {  // 成绩相等
                ranks[scores[i].first] = {ranks[scores[i - 1].first].c, 0, 0, 0};
                continue;
            }
        }
        ranks[scores[i].first] = {i + 1, 0, 0, 0};
    }

    sort(scores.begin(), scores.end(), [](const P& a, const P& b) {
                return a.second.m > b.second.m;
            });
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (scores[i].second.m == scores[i - 1].second.m) {  // 成绩相等
                ranks[scores[i].first].m = ranks[scores[i - 1].first].m;   // 排名相同
                continue;
            }
        }
        ranks[scores[i].first].m = i + 1;
    }

    sort(scores.begin(), scores.end(), [](const P& a, const P& b) {
                return a.second.e > b.second.e;
            });
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (scores[i].second.e == scores[i - 1].second.e) {  // 成绩相等
                ranks[scores[i].first].e = ranks[scores[i - 1].first].e;   // 排名相同
                continue;
            }
        }
        ranks[scores[i].first].e = i + 1;
    }

    sort(scores.begin(), scores.end(), [](const P& a, const P& b) {
                return a.second.a > b.second.a;
            });
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            if (scores[i].second.a == scores[i - 1].second.a) {  // 成绩相等
                ranks[scores[i].first].a = ranks[scores[i - 1].first].a;   // 排名相同
                continue;
            }
        }
        ranks[scores[i].first].a = i + 1;
    }

    for (int i = 0; i < k; ++i) {
        cin >> id;
        auto fnd = ranks.find(id);
        if (fnd == ranks.end()) {
            cout << "N/A" << endl;
        }
        else {
            R r(fnd->second);
            r.printRank();
        }
    }

    return 0;
}
