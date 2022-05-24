#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int value;
    int left, right;
    Node(int value = 0)
        : value(value), left(-1), right(-1) {}
};

int n;
int e = 0;
int values[110];
Node nodes[110];

void traversal(int root) {
    if (root == -1) return ;

    traversal(nodes[root].left);
    nodes[root].value = values[e++];
    traversal(nodes[root].right);
}

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        nodes[i].left = l;
        nodes[i].right = r;
    }

    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    sort(values, values + n);

    traversal(0);

    queue<int> q;
    q.push(0);
    bool first = true;
    while (!q.empty()) {
        int head = q.front();
        q.pop();
        if (head < 0) continue;
        if (first) first = false;
        else cout << ' ';
        cout << nodes[head].value;
        q.push(nodes[head].left);
        q.push(nodes[head].right);
    }
    cout << endl;

    return 0;
}
