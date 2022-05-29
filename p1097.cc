#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <iomanip>
using namespace std;
#define N1 100000
#define N2 100001
#define N 100002

struct Node {
    int n;
    int next;
    Node(int n = 0, int next = -1)
        : n{n}, next{next} {}
};

Node nodes[N];
int start_addr, n;
int dup_end = N2;

int abs(int n) {
    return n < 0 ? -n : n;
}

int main()
{
    cin >> start_addr >> n;
    for (int i = 0; i < n; ++i) {
        int s, d, nxt;
        cin >> s >> d >> nxt;
        nodes[s] = {d, nxt};
    }
    nodes[N1].next = start_addr;
    nodes[N2].next = -1;

    int i = start_addr, prev = N1;
    unordered_set<int> vis;
    while (i >= 0) {
        auto fnd = vis.find(::abs(nodes[i].n));
        if (fnd != vis.end()) {
            nodes[prev].next = nodes[i].next;
            nodes[dup_end].next = i;
            nodes[i].next = -1;
            dup_end = i;
            // prev = prev;
            i = nodes[prev].next;
        }
        else {
            vis.insert(::abs(nodes[i].n));
            prev = i;
            i = nodes[i].next;
        }
    }

    i = start_addr;
    while (i != -1) {
        printf("%.5d %d ", i, nodes[i].n);
        if (nodes[i].next < 0) {
            printf("%d\n", nodes[i].next);
        }
        else {
            printf("%.5d\n", nodes[i].next);
        }
        i = nodes[i].next;
    }
    i = nodes[N2].next;
    while (i != -1) {
        printf("%.5d %d ", i, nodes[i].n);
        if (nodes[i].next < 0) {
            printf("%d\n", nodes[i].next);
        }
        else {
            printf("%.5d\n", nodes[i].next);
        }
        i = nodes[i].next;
    }


    return 0;
}
