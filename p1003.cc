#include <iostream>
#include <cstring>
using namespace std;

#define N 510
const int INF = 0x3f3f3f3f;

struct State {
    int r;
    int distance;
    int value;
    int cnt;
};

State f[N];
int dis[N][N], dup[N][N], vis[N];
int n, m, start, finish;

void init() {
    memset(dis, 0x3f, sizeof(dis));
    memset(dup, 0, sizeof(dup));

    for (int i = 0; i < n; ++i) {
        cin >> f[i].r;
        f[i].distance = (i == start ? 0 : INF);
        f[i].value = (i == start ? f[i].r : 0);
        f[i].cnt = (i == start ? 1 : 0);
    }
    for (int i = 0; i < m; ++i) {
        int b, e, d;
        cin >> b >> e >> d;
        dis[b][e] = dis[e][b] = d;
        ++dup[b][e];
        ++dup[e][b];
    }
}

void dijkstra() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        int x = 0, now = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && f[j].distance <= now) {
                now = f[x = j].distance;
            }
        }
        vis[x] = 1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                if (f[x].distance + dis[x][j] == f[j].distance) {
                    f[j].cnt += f[x].cnt * dup[x][j];
                    f[j].value = max(f[j].value, f[x].value + f[j].r);
                }
                else if (f[x].distance + dis[x][j] < f[j].distance) {
                    f[j].cnt = f[x].cnt * dup[x][j];
                    f[j].distance = f[x].distance + dis[x][j];
                    f[j].value = f[x].value + f[j].r;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> start >> finish;
    init();
    dijkstra();

    cout << f[finish].cnt << " " << f[finish].value << endl;

    return 0;
}
