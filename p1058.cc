#include <iostream>
using namespace std;

int main()
{
    char sep;
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> sep >> b1 >> sep >> c1;
    cin >> a2 >> sep >> b2 >> sep >> c2;

    int sc = c1 + c2;
    int sb = b1 + b2 + sc / 29;
    sc %= 29;
    int sa = a1 + a2 + sb / 17;
    sb %= 17;

    cout << sa << '.' << sb << '.' << sc << endl;

    return 0;
}
