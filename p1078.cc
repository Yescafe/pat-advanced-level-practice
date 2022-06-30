#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define N 10005

bool used[N];
int n, m;

bool isPrime(int a) {
    if (a == 0 || a == 1) return false;
    for (int f = 2; f <= a / 2; ++f) {
        if (a % f == 0) return false;
    }
    return true;
}

void insert(int a) {
    for (int s = 0; s < n; ++s) {
        int idx = (a + s * s) % n;
        if (!used[idx]) {
            used[idx] = true;
            cout << idx % n;
            return ;
        }
    }
    cout << '-';
}

int main()
{
    memset(used, 0, sizeof(used));

    cin >> n >> m;

    while (!isPrime(n)) ++n;

    while (m--) {
        int a;
        cin >> a;
        insert(a);
        if (m != 0) cout << ' ';
    }
    cout << endl;

    return 0;
}
