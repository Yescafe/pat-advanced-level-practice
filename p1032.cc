#include <iostream>
#include <iomanip>
using namespace std;
#define N 100000

struct Node {
    char c;
    int next;
    bool vis;
} ns[N];

int main()
{
    int sa1, sa2, n;
    cin >> sa1 >> sa2 >> n;
    for (int i = 0; i < n; ++i) {
        int addr, next;
        char c;
        cin >> addr >> c >> next;
        ns[addr] = {c, next, false};
    }

    int it = sa1;
    while (it >= 0) {
        ns[it].vis = true;
        it = ns[it].next;
    }
    it = sa2;
    while (it >= 0) {
        if (ns[it].vis) {
            cout << setfill('0') << setw(5) << it << endl;
            return 0;
        }
        it = ns[it].next;
    }

    cout << -1 << endl;

    return 0;
}
