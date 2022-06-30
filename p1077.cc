#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define N 105

string arr[N];

int main()
{
    int n;
    cin >> n;
    getline(cin, arr[N - 1]);

    for (int i = 0; i < n; ++i) {
        getline(cin, arr[i]);
        // cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    stringstream ss;
    for (int c = 1; ; ++c) {
        if (arr[0].length() < c) break;
        char base = arr[0][arr[0].length() - c];
        bool eq = true;
        for (int i = 1; i < n; ++i) {
            if (arr[i].length() < c || base != arr[i][arr[i].length() - c]) {
                eq = false;
                break;
            }
        }

        if (!eq) break;
        ss << base;
    }

    string kuchiguse = ss.str();
    if (kuchiguse.empty()) {
        cout << "nai" << endl;
        return 0;
    }
    reverse(kuchiguse.begin(), kuchiguse.end());
    cout << kuchiguse << endl;

    return 0;
}
