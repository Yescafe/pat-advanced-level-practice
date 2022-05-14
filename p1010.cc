#include <iostream>
#include <cctype>
#include <algorithm>
using ll = long long;
using namespace std;

ll dec(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    }
    else {
        return ch - 'a' + 10;
    }
}

ll getDec(const string& s, int base) {
    ll e = 1;
    ll dec_n = 0;

    for (int i = s.length() - 1; i >= 0; --i, e *= base) {
        dec_n += dec(s[i]) * e;
    }

    return dec_n;
}

ll findR(ll who, const string& other) {
    ll low = -1;
    for (auto& c : other) {
        low = max(low, dec(c));
    }
    ++low;
    ll high = max(low, who);
    while (low <= high) {
        ll mid = (high + low) / 2;
        ll a = getDec(other, mid);
        if (a == who) return mid;
        else if (a < 0 || a > who) {   // 超出 long long 范围了所以这里要 a < 0，根本想不到
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    string a, b;
    ll tag, base;
    cin >> a >> b >> tag >> base;
    string *who, *other;
    if (tag == 1) {
        who = &a;
        other = &b;
    }
    else {
        who = &b;
        other = &a;
    }

    ll dec_of_who = getDec(*who, base);
    auto ans_r = findR(dec_of_who, *other);

    if (ans_r < 0) {
        cout << "Impossible" << endl;
    }
    else {
        cout << ans_r << endl;
    }

    return 0;
}
