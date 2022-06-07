#include <iostream>
using namespace std;
#define N 100010

int s[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (i != s[i]) {
            while (s[0] != 0) {
                swap(s[0], s[s[0]]);
                ++ans;
            }
            if (i != s[i]) {
                swap(s[0], s[i]);
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
