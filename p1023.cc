#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// using ll = unsigned long long;

string times2(string n) {
    int len = n.length();
    string ans(len + 1, '0');
    int carry = 0;
    for (int i = 0; i < len; ++i) {
        int b = (n[len - 1 - i] - '0') * 2 + carry;
        carry = b / 10;
        int bit = b % 10;
        ans[len - i] = bit + '0';
    }
    ans[0] = carry + '0';

    return ans;
}

int main()
{
    // ll n;
    string ns;
    cin >> ns;
    string ns2 = times2(ns);
    int start_pos = ns2.find_first_not_of("0");
    if (ns.length() != ns2.length() - start_pos) {
        cout << "No" << endl;
    }
    else {
        cout << (is_permutation(ns.begin(), ns.end(), ns2.begin() + start_pos) ? "Yes" : "No") << endl;
    }
    cout << ns2.substr(start_pos) << endl;

    return 0;
}
