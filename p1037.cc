#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int n, m;
    vector<int> ns, ms;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ns.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        ms.push_back(a);
    }

    deque<int> pns, nns, pms, nms;
    sort(ns.begin(), ns.end());
    copy_if(ns.begin(), ns.end(), back_inserter(pns), [](const int& a) { return a > 0; });
    copy_if(ns.begin(), ns.end(), back_inserter(nns), [](const int& a) { return a < 0; });
    sort(ms.begin(), ms.end());
    copy_if(ms.begin(), ms.end(), back_inserter(pms), [](const int& a) { return a > 0; });
    reverse(pms.begin(), pms.end());
    copy_if(ms.begin(), ms.end(), back_inserter(nms), [](const int& a) { return a < 0; });

    int ans = 0;
    for (auto& pm : pms) {
        if (pns.empty()) {
            break;
        }
        ans += pm * pns.back();
        pns.pop_back();
    }
    for (auto& nm : nms) {
        if (nns.empty()) {
            break;
        }
        ans += nm * nns.front();
        nns.pop_front();
    }

    cout << ans << endl;

    return 0;
}
