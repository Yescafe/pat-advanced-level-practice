#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ns = to_string(n);
    int left = n, right = 0;
    int ans = 0;
    int a = 1;
    int curr;
    for (int i = 0; i < ns.length(); ++i, a *= 10) {
        left = n / (a * 10);
        curr = n / a % 10;
        right = n % a;
#ifndef ONLINE_JUDGE
        cout << left << " " << curr << " " << right << endl;
#endif
        if (curr == 0)
            ans += left * a;
        else if (curr == 1)
            ans += left * a + right + 1;
        else
            ans += (left + 1) * a;
    }

    cout << ans << endl;
    return 0;
}
