#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 10005

int cnts[N];
vector<int> lst;

int main()
{
    memset(cnts, 0, sizeof(cnts));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++a[cnts];
        lst.push_back(a);
    }
    
    for (auto& c : lst) {
        if (cnts[c] == 1) {
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;

    return 0;
}
