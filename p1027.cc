#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string to13R(int a) {
    string ans;
    if (a == 0) return {"00"};
    while (a != 0) {
        int b = a % 13;
        ans.push_back(b < 10 ? b + '0' : b - 10 + 'A');
        a /= 13;
    }
    if (ans.length() < 2)
        ans.push_back('0');
    swap(ans[0], ans[1]);
    return ans;
}

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    cout << '#' << to13R(r) << to13R(g) << to13R(b) << endl;

    return 0;
}
