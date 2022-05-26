#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    vector<string> v;
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
                return a + b < b + a;
            });

    stringstream ss;
    for (auto& s : v) {
        ss << s;
    }
    string ans = ss.str();
    while (ans.size() > 1 && ans.front() == '0')
        ans.erase(ans.begin());
    cout << ans << endl;

    return 0;
}
