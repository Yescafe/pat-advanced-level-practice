#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um;

int main()
{
    int n, m, a;
    cin >> n >> m;
    int half = n * m / 2;
    int res;
    for (int i = 0; i < m; ++i) {
        for (int ii = 0; ii < n; ++ii) {
            cin >> a;
            int cnt = ++um[a];
            if (cnt > half) {
                res = a;
                cout << res << endl;
                return 0;
            }
        }
    }
    
    cout << -1 << endl;

    return 0;
}
