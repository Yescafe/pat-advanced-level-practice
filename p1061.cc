#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

string weekname[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int weeki = 0, houri = 0, minutei = 0;
    int i;
    for (i = 0; i < a.length() && i < b.length(); ++i) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            weeki = a[i];
            break;
        }
    }

    for (i = i + 1; i < a.length() && i < b.length(); ++i) {
        if (a[i] == b[i] && (isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N'))) {
            houri = a[i];
            break;
        }
    }

    for (i = 0; i < c.length() && i < d.length(); ++i) {
        if (c[i] == d[i] && isalpha(c[i])) {
            minutei = i;
            break;
        }
    }

    cout << weekname[weeki - 'A'] << " "
         << setfill('0') << setw(2) << (!isalpha(houri) ? houri - '0' : houri - 'A' + 10) << ":"
         << setfill('0') << setw(2) << minutei << endl;

    return 0;
}

