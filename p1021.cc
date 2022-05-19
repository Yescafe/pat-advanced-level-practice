#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define N 100050

vector<int> graph[N];
int vis[N];
vector<int> roots;
int max_depth = -1;
int n;

void dfs(int k, int depth) {
    if (depth > max_depth) {
        roots.clear();
        max_depth = depth;
        roots.push_back(k);
    } else if (depth == max_depth) {
        roots.push_back(k);
    }

    for (auto i : graph[k]) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i, depth + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cnts = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++cnts;
            dfs(i, 0);
        }
    }

    int s = roots[0];
    set<int> ans(roots.begin(), roots.end());
    roots.clear();
    max_depth = -1;
    memset(vis, 0, sizeof(vis));
    if (cnts > 1) {
        cout << "Error: " << cnts << " components" << endl;
    }
    else {
        dfs(s, 0);
        for (auto& i : roots) ans.insert(i);
        for (auto& i : ans) cout << i << endl;
    }

    return 0;
}
