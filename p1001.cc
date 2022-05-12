#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        int ans = a + b;
        bool neg = false;
        if (ans < 0) {
            ans = -ans;
            neg = true;
        }
        if (ans == 0) {
            cout << 0 << endl;
            continue;
        }
        string output;
        int cnts = 0;
        while (ans) {
            output.push_back(ans % 10 + '0');
            cnts++;
            ans /= 10;
            if (ans != 0 && cnts % 3 == 0) {
                output.push_back(',');
            }
        }
        if (neg)
            output.push_back('-');
        reverse(output.begin(), output.end());
        cout << output << endl;
    }
    return 0;
}
