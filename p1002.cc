#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n) {
        map<int, double> poly;
        for (int i = 0; i < n; ++i) {
            int a;
            double b;
            cin >> a >> b;
            poly[a] += b;
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a;
            double b;
            cin >> a >> b;
            poly[a] += b;
        }
        vector<pair<int, double>> ans(poly.begin(), poly.end());
        ans.erase(remove_if(ans.begin(), ans.end(), [](const pair<int, double>& p) { return p.second == 0.0; }), ans.end());
        sort(ans.begin(), ans.end(), [](const pair<int, double>& l, const pair<int, double>& r) {
                    return l.first > r.first;
                });
        cout << ans.size();
        bool first = true;
        for (auto& p : ans) {
            if (p.second != 0.0) {
                cout << " " << p.first << " " << fixed << setprecision(1) << p.second;
            }
        }
        cout << endl;
    }
    return 0;
}
