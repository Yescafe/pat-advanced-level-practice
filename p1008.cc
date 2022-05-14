#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int prev = 0;
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        int next;
        cin >> next;
        if (next < prev) {
            cost += (prev - next) * 4;
        }
        else {
            cost += (next - prev) * 6;
        }
        prev = next;
    }
    cost += n * 5;
    cout << cost << endl;
    return 0;
}
