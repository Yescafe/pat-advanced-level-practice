#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

set<int> ss[51];

double mergeSet(int i, int j) {
    int nc = 0, nt = ss[j].size();
    for (auto& a : ss[i]) {
        if (ss[j].find(a) != ss[j].end()) {
            ++nc;
        }
        else {
            ++nt;
        }
    }

    return (double) nc / nt;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int nn;
        cin >> nn;
        for (int j = 0; j < nn; ++j) {
            int a;
            cin >> a;
            ss[i].insert(a);
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << setprecision(1) << fixed << mergeSet(a, b) * 100 << '%' << endl;
    }

    return 0;
}
