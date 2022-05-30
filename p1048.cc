#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> coins;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++coins[a];
    }

    for (auto& p : coins) {
        int v1 = p.first;
        int v2 = m - p.first;
        if (v1 == v2) {
            if (p.second >= 2) {
                cout << v1 << ' ' << v1 << endl;
                return 0;
            }
        }
        else if (coins.find(v2) != coins.end()) {
            cout << v1 << ' ' << v2 << endl;
            return 0;
        }
    }

    cout << "No Solution" << endl;

    return 0;
}
