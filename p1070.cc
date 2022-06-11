#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

struct Mooncake {
    double amount;
    double price;
};

vector<Mooncake> v;

int main()
{
    int n;
    double req;
    cin >> n >> req;

    v.assign(n, {});
    for (int i = 0; i < n; ++i) {
        cin >> v[i].amount;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].price;
    }

    sort(v.begin(), v.end(), [](const Mooncake& a, const Mooncake& b) {
                return a.price / a.amount > b.price / b.amount;
            });

    double ans = 0;
    for (auto& mc : v) {
        if (req >= mc.amount) {
            ans += mc.price;
            req -= mc.amount;
        } else {
            ans += mc.price / mc.amount * req;
            req = 0;
        }

        if (req <= 0) {
            break;
        }
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}
