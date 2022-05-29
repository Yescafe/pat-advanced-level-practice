#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int bound = sqrt(n) + 1;
    int len = 0, head = 0;
    for (int i = 2; i <= bound; ++i) {
        int prod = 1;
        int j;
        for (j = i; j <= bound; ++j) {
            if (prod * j / j != prod) break;
            prod *= j;
            if (n % prod != 0) {
                break;
            }
        }
        if (j - i > len) {
            len = j - i;
            head = i;
        }
    }

    if (len == 0) {
        cout << 1 << endl << n << endl;
    }
    else {
        cout << len << endl;
        for (int i = 0; i < len; ++i) {
            if (i != 0) cout << '*';
            cout << head++;
        }
        cout << endl;
    }

    return 0;
}
