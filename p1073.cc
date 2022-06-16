#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sci;
    cin >> sci;

    string s, e;

    const auto n = sci.length();
    int i;
    for (i = 1; i < n; ++i) {
        if (sci[i] == 'E') {
            ++i;
            break;
        }
        if (i == 2) {
            continue;
        }
        s += sci[i];
    }

    for (; i < n; ++i) {
        e += sci[i];
    }

#ifndef ONLINE_JUDGE
    cout << "s = " << s << ", e = " << stoi(e) << endl;
#endif  /* ONLINE_JUDGE */

    int en = stoi(e);
    cout << sci[0];
    if (en == 0) {
        cout << s[0] << ".";
        for (int i = 1; i < s.length(); ++i) {
            cout << s[i];
        }
    }
    else if (en < 0) {
        cout << "0.";
        ++en;
        while (en++) {
            cout << '0';
        }
        cout << s;
    }
    else {
        cout << s[0];
        int bit_cnt = 0;
        for (int i = 1; i < s.length(); ++i) {
            cout << s[i];
            ++bit_cnt;
            if (i == en) {
                if (i == s.length() - 1 && bit_cnt >= en) break;
                cout << ".";
            }
        }

        while (bit_cnt < en) {
            cout << '0';
            ++bit_cnt;
        }
    }

    endl(cout);

    return 0;
}
