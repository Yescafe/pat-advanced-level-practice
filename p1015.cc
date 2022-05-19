#include <iostream>
#include <string>
using namespace std;
#define N 100050
using ll = long long;

int primes[N];

ll reverseByR(int d, int r) {
    if (d == 0) return 0;
    string sn;
    while (d != 0) {
        sn.push_back(d % r + '0');
        d /= r;
    }
    ll e = 1;
    ll ans = 0;
    for (auto it = sn.rbegin(); it != sn.rend(); ++it, e *= r) {
        ans += (*it - '0') * e;
    }
    return ans;
}

int main()
{
    for (int i = 0; i < N; ++i)
        primes[i] = true;
    primes[0] = primes[1] = false;
    for (int i = 2; i < N; ++i) {
        if (primes[i]) {
            for (int f = 2; f * i < N; ++f) {
                primes[f * i] = false;
            }
        }
    }

    int n, r;
    while (cin >> n) {
        if (n < 0) break;
        cin >> r;
        cout << (primes[n] && primes[reverseByR(n, r)] ? "Yes" : "No") << endl;
    }

    return 0;
}
