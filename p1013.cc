#include <iostream>
#include <cstring>
using namespace std;
#define N 1010

bool roads[N][N];
bool vis[N];
int n;

void dfs(int curr) {
    for (int i = 1; i <= n; ++i) {
        if (roads[i][curr] && !vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }
}

int find_without_a(int ignore) {
    memset(vis, 0, sizeof(vis));
    vis[ignore] = true;
    int cnts = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++cnts;
            dfs(i);
        }
    }
    return cnts;
}

int main()
{
    memset(roads, 0, sizeof(roads));
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        roads[a][b] = roads[b][a] = true;
    }

    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        cout << find_without_a(a) - 1 << endl;
    }

    return 0;
}
