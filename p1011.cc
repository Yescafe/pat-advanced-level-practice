#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    double w, t, l;
    double profit = 0.65;
    while (cin >> w >> t >> l) {
        if (w > t && w > l) {
            cout << "W ";
            profit *= w;
        }
        else if (t > w && t > l) {
            cout << "T ";
            profit *= t;
        }
        else {
            cout << "L ";
            profit *= l;
        }
    }
    cout << fixed << setprecision(2) << (profit - 1) * 2 << endl;
    return 0;
}
