#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string add(const string& a, const string& b) {
    stringstream ans;
    int la = a.length();
    int carry = 0;
    for (int i = 0; i < la; ++i) {
        int d = ((int)a[i] + b[i] - 2 * '0') + carry;
        carry = d / 10;
        ans << char(d % 10 + '0');
    }
    if (carry) ans << char(carry + '0');
    return ans.str();
}

bool isPalindromic(const string& a) {
    int len = a.length();
    for (int i = 0; i < len / 2; ++i) {
        if (a[i] != a[len - 1 - i]) return false;
    }
    return true;
}

int main()
{
    // int n, k;
    int k;
    string ns;    // 好像是 testcases 里有 0 开头的样例，很奇怪
    cin >> ns >> k;
    // string ns = to_string(n);
    if (isPalindromic(ns) || k == 0) {
        cout << ns << endl << 0 << endl;
        return 0;
    }
    string ans;

    for (int step = 1; step <= k; ++step) {
        string rns(ns.rbegin(), ns.rend());
        ans = add(ns, rns);
        while (ans.back() == '0') ans.pop_back();
        if (isPalindromic(ans)) {
            cout << ans << endl << step << endl;
            return 0;
        }
        ns = ans;
    }
    reverse(ns.begin(), ns.end());
    cout << ns << endl << k << endl;

    return 0;
}
