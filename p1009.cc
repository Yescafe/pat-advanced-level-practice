#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
constexpr double EPS = 1e-6;

int main() {
    int n, m;
    map<int, double> a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int e;
        double c;
        cin >> e >> c;
        a[e] += c;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int e;
        double c;
        cin >> e >> c;
        b[e] += c;
    }

    map<int, double> ans;
    for (auto& p1 : a) {
        for (auto& p2 : b) {
            auto e = p1.first + p2.first;
            auto c = p1.second * p2.second;
            if (abs(c - 0.0) < EPS) {      // c == 0
                continue;
            }
            ans[e] += c;
        }
    }

    vector<pair<int, double>> v(ans.begin(), ans.end());
    v.erase(remove_if(v.begin(), v.end(), [](const pair<int, double>& a) { return abs(a.second - 0) < EPS; }), v.end());
    sort(v.begin(), v.end(), [](const pair<int, double>& a, const pair<int, double>& b) {
                return a.first > b.first;
            });
    cout << v.size();
    for (auto p : v) {
        cout << " " << p.first << " " << fixed << setprecision(1) << p.second;
    }
    cout << endl;

    return 0;
}
