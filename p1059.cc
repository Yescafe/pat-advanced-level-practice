#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long n;
    cin >> n;
    if (n == 1) {
        cout << "1=1" << endl;
        return 0;
    }
    cout << n << "=";

    bool firstIn = true;
    for (long i = 2, nn = n; i <= n && nn > 1; ++i) {
        int cnt = 0;
        while (nn % i == 0) {
            nn /= i;
            ++cnt;
        }

        if (cnt > 0) {
            if (firstIn) firstIn = false;
            else cout << '*';
            if (cnt == 1) cout << i;
            else if (cnt > 1) cout << i << '^' << cnt;
        }
    }
    cout << endl;

    return 0;
}
