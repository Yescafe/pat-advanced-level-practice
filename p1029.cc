#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    int n, m;
    vector<int> ln, lm;
    vector<int> merged;

    cin >> n;
    ln.reserve(n);
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        ln.push_back(t);
    }
    cin >> m;
    lm.reserve(m);
    for (int i = 0; i < m; ++i) {
        int t; cin >> t;
        lm.push_back(t);
    }

    merge(ln.begin(), ln.end(), lm.begin(), lm.end(), back_inserter(merged));
    int median_pos = (merged.size() - 1) / 2;
    cout << merged[median_pos] << endl;

    return 0;
}
