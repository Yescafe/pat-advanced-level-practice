#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void toRRev(vector<int>& ns, int n, int r) {
    while (n != 0) {
        ns.push_back(n % r);
        n /= r;
    }
}

int main()
{
    int n, r;
    cin >> n >> r;
    if (n == 0) {
        cout << "Yes\n0\n";
    }
    else {
        vector<int> ns;
        toRRev(ns, n, r);
        if (ns[0] == 0) {
            cout << "No" << endl;
            for (int i = ns.size() - 1; i >= 0; --i) {
                if (i != ns.size() - 1) cout << " ";
                cout << ns[i];
            }
            cout << endl;
            return 0;
        }
        bool palin = true;
        for (int i = 0; i < ns.size() / 2; ++i) {
            if (ns[i] != ns[ns.size() - 1 - i]) {
                palin = false;
                break;
            }
        }
        if (palin) {
            cout << "Yes" << endl;
            for (int i = 0; i < ns.size(); ++i) {
                if (i != 0) cout << " ";
                cout << ns[i];
            }
        }
        else {
            cout << "No" << endl;
            for (int i = ns.size() - 1; i >= 0; --i) {
                if (i != ns.size() - 1) cout << " ";
                cout << ns[i];
            }
        }
        cout << endl;
    }
    return 0;
}
