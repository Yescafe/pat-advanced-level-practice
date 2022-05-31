#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int addr;
    int n;
    int next;
    Node(int addr = 0, int n = 0, int next = -1) : addr{addr}, n{n}, next{next} {}
} nodes[100000];

int main()
{
    int n, start_pos;
    cin >> n >> start_pos;
    vector<Node> ns;
    ns.reserve(n);

    for (int i = 0; i < n; ++i) {
        int s, d, e;
        cin >> s >> d >> e;
        nodes[s].addr = s;
        nodes[s].n = d;
        nodes[s].next = e;
    }

    int j = start_pos;
    while (j >= 0) {
        ns.push_back(nodes[j]);
        j = nodes[j].next;
    }

    sort(ns.begin(), ns.end(), [](const Node& a, const Node& b) { return a.n < b.n; });
    printf("%zu %.5d\n", ns.size(), ns.front().addr);
    for (int i = 0; i < ns.size(); ++i) {
        printf("%.5d %d ", ns[i].addr, ns[i].n);
        if (i != ns.size() - 1) {
            printf("%.5d\n", ns[i + 1].addr);
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}
