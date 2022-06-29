#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> follower[1005];
bool vis[1005];
int cnt;
int n, l;

void bfs(int a) {
    int depth = 1;
    queue<int> q;
    q.push(a);
    vis[a] = true;
    while (!q.empty() && depth <= l) {
        int size = q.size();
        while (size--) {
            int f = q.front();
            q.pop();
            for (auto& a : follower[f]) {
                if (vis[a]) continue;

                vis[a] = true;
                ++cnt;

                q.push(a);
            }
        }
        ++depth;
    }
}

int main()
{
    cin >> n >> l;

    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            follower[a].push_back(i);
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;

        memset(vis, 0, sizeof(vis));
        cnt = 0;

        bfs(a);

        cout << cnt << endl;
    }

    return 0;
}
