#include <iostream>
using namespace std;

using ll = long long;

struct Rational {
    ll n, d;
    Rational() = default;
    Rational(ll n, ll d) : n{n}, d{d} {}
    friend Rational operator+(const Rational& a, const Rational& b) {
        ll cd = a.d / gcd(a.d, b.d) * b.d;
        ll an = a.n * (cd / a.d);
        ll bn = b.n * (cd / b.d);
        Rational c{an + bn, cd};
        ll g = gcd(c.n < 0 ? -c.n : +c.n, c.d);
        c.n /= g;
        c.d /= g;
        return c;
    }
    static ll gcd(ll a, ll b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    friend istream& operator>>(istream& is, Rational& a) {
        char slash;
        return (cin >> a.n >> slash >> a.d);
    }
    friend ostream& operator<<(ostream& os, Rational& a) {
        bool neg = a.n < 0;
        a.n = a.n < 0 ? -a.n : +a.n;
        if (a.d == 1) {
            if (neg) os << '-';
            return (os << a.n);
        } else if (a.n < a.d) {
            if (neg) os << '-';
            return (os << a.n << '/' << a.d);
        } else {
            if (neg) os << '-';
            os << a.n / a.d << ' ';
            if (neg) os << '-';
            return (os << a.n % a.d << '/' << a.d);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Rational r(0, 1);
    for (int i = 0; i < n; ++i) {
        Rational a;
        cin >> a;
        r = r + a;
    }

    cout << r << endl;

    return 0;
}
