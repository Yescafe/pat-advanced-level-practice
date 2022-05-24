#include <iostream>
#include <vector>
#include <numeric>
#include <stack>
#include <iterator>
using namespace std;

int main()
{
    int maxs, n, k;
    cin >> maxs >> n >> k;
    for (int _ = 0; _ < k; ++_) {
        vector<int> pd;
        pd.reserve(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            pd.push_back(a);
        }
        stack<int> s;
        int i = 1, ii = 0;
        while (ii < n) {
            // cout << i << ", " << ii << endl;
            if (!s.empty() && s.top() == pd[ii]) {
                s.pop();
                ++ii;
            }
            else if (s.size() < maxs) {
                s.push(i++);
            }
            else {
                break;
            }
        }

        if (s.empty() && ii == n) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
