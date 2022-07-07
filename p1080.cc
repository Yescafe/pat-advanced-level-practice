#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student {
    int id;
    int e;
    int i;
    friend bool operator==(const Student& a, const Student& b) {
        return a.e == b.e && a.i == b.i;
    }
};

vector<Student> s;
vector<Student> p[105];
int quota[105];
int adm[40010][5];

bool cmp(const Student& a, const Student& b) {
    if (a.e + a.i != b.e + b.i) {
        return a.e + a.i > b.e + b.i;
    }
    return a.e > b.e;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> quota[i];
    }

    for (int i = 0; i < n; ++i) {
        Student stu;
        stu.id = i;
        cin >> stu.e >> stu.i;
        s.push_back(stu);
        for (int ii = 0; ii < k; ++ii) {
            cin >> adm[i][ii];
        }
    }

    sort(s.begin(), s.end(), cmp);

    for (auto& stu : s) {
        for (int i = 0; i < k; ++i) {
            auto school = adm[stu.id][i];
            if (p[school].size() < quota[school]) {
                p[school].push_back(stu);
                break;
            } else {
                if (p[school].back() == stu) {
                    p[school].push_back(stu);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        sort(p[i].begin(), p[i].end(), [](const Student& a, const Student& b) { return a.id < b.id; });
        for (int j = 0; j < p[i].size(); ++j) {
            if (j != 0) cout << ' ';
            cout << p[i][j].id;
        }
        endl(cout);
    }

    return 0;
}