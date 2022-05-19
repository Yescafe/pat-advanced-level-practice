#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.length();

    int h = (n + 2) / 3;
    int w = n - h * 2;
    for (int i = 0; i < h - 1; ++i) {
        cout << str[i];
        for (int j = 0; j < w; ++j) {
            cout << " ";
        }
        cout << str[n - 1 - i];
        cout << endl;
    }
    for (int i = h - 1; i < n - (h - 1); ++i) {
        cout << str[i];
    }
    cout << endl;

    return 0;
}
