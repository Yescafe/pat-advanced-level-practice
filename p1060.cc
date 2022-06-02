#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string asSpecMark(const string& prefix, int exp) {
    stringstream ss;
    ss << '0';
    if (!prefix.empty()) {
        ss << '.' << prefix;
    }
    ss << "*10^" << exp;
    return ss.str();
}

int main()
{
    int precision;
    string n1, n2;
    cin >> precision >> n1 >> n2;

    int e1 = n1.length(), e2 = n2.length();

    for (int i = 0; i < n1.length(); ++i) {
        if (n1[i] == '.') {
            n1.erase(n1.begin() + i);
            e1 = i;
            break;
        }
    }
    while (!n1.empty() && n1.front() == '0') {
        --e1;
        n1.erase(n1.begin());
    }
    if (n1.empty()) e1 = 0;

    for (int i = 0; i < n2.length(); ++i) {
        auto& d = n2[i];
        if (d == '.') {
            n2.erase(n2.begin() + i);
            e2 = i;
            continue;
        }
    }
    while (!n2.empty() && n2.front() == '0') {
        --e2;
        n2.erase(n2.begin());
    }
    if (n2.empty()) e2 = 0;

#ifndef ONLINE_JUDGE
    cout << "n = 0." << n1 << "*10^" << e1 << endl;
#endif

    string prefix_of_n1, prefix_of_n2;
    for (int i = 0; i < precision; ++i) {
        prefix_of_n1.push_back(i < n1.length() ? n1[i] : '0');
        prefix_of_n2.push_back(i < n2.length() ? n2[i] : '0');
    }

    if (e1 != e2) {
        cout << "NO " << asSpecMark(prefix_of_n1, e1) << ' ' << asSpecMark(prefix_of_n2, e2) << endl;
    }
    else {
        if (prefix_of_n1 != prefix_of_n2) {
            // cout << "NO 0." << prefix_of_n1 << "*10^" << e1 << " " << "0." << prefix_of_n2 << "*10^" << e2 << endl;
            cout << "NO " << asSpecMark(prefix_of_n1, e1) << ' ' << asSpecMark(prefix_of_n2, e2) << endl;
        }
        else {
            cout << "YES " << asSpecMark(prefix_of_n1, e1) << endl;
        }
    }

    return 0;
}
