#include <iostream>
#include <algorithm>
using namespace std;
#define N 1010

int seq[N], lvl[N];
int k = 0;
int n;

void inorder(int i) {
    if (i >= n) return ;
    inorder(i * 2 + 1);
    lvl[i] = seq[k++];
    inorder(i * 2 + 2);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    sort(seq, seq + n);
    inorder(0);

    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << lvl[i];
    }
    cout << endl;

    return 0;
}
