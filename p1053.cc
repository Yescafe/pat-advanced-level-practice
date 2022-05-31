#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100

struct Node {
    int weight;
    vector<int> children;
    Node(int weight = 0) : weight{weight} {}
} nodes[N];

int n, l, s;
vector<int> seq;
int sum = 0;
vector<vector<int>> res;

void printSeq() {
    for (int i = 0; i < seq.size(); ++i) {
        if (i != 0) cout << ' ';
        cout << seq[i];
    }
    cout << endl;
}

void dfs(int r) {
    seq.push_back(nodes[r].weight);
    sum += nodes[r].weight;
    if (nodes[r].children.empty()) {
        if (sum == s) {
            res.push_back(seq);
        }
        seq.pop_back();
        sum -= nodes[r].weight;
        return ;
    }

    for (auto& next : nodes[r].children) {
        dfs(next);
    }
    
    seq.pop_back();
    sum -= nodes[r].weight;
}

void bfs() {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            cout << q.front() << ':' << nodes[q.front()].weight << ' ';
            for (auto& k : nodes[q.front()].children) {
                cout << q.front() << "->" << k << ' ';
                q.push(k);
            }
            q.pop();
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> l >> s;

    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].weight;
    }

    for (int i = 0; i < l; ++i) {
        int idx, ni;
        cin >> idx >> ni;
        for (int j = 0; j < ni; ++j) {
            int ii;
            cin >> ii;
            nodes[idx].children.push_back(ii);
        }
        sort(nodes[idx].children.begin(), nodes[idx].children.end());
    }

    dfs(0);

    sort(res.begin(), res.end(), [](const vector<int>& a, const vector<int>& b) {
                auto k = min(a.size(), b.size());
                for (int i = 0; i < k; ++i) {
                    if (a[i] > b[i]) {
                        return true;
                    }
                    else if (a[i] < b[i]) {
                        return false;
                    }
                }
                return a.size() > b.size();
            });
    for (auto& v : res) {
        for (int i = 0; i < v.size(); ++i) {
            if (i != 0) cout << ' ';
            cout << v[i];
        }
        cout << endl;
    }

    return 0;
}


