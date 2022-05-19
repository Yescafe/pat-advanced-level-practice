#include <iostream>
#include <deque>
#include <iomanip>
using namespace std;
constexpr int START_TIME = 8 * 60;
constexpr int END_TIME  = 17 * 60;

deque<pair<int, int>> windows[22];
int customers[1021];
int done[1021];
int e = 0;
int n; // number of windows

pair<int, int> getTime(int t) {
    return make_pair(t / 60, t % 60);
}

// #define DEBUG__

void printInfo() {
#ifdef DEBUG__
    cout << "=======" << endl;
    for (int i = 0; i < n; ++i) {
        for (auto& p : windows[i]) {
            cout << p.first << ':' << p.second << ' ';
        }
        cout << endl;
    }
#endif
}

int main()
{
    int m; // maximum capacity of each line
    int k; // number of customers
    int q; // number of customer queries

    cin >> n >> m >> k >> q;

    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        customers[i] = t;
        done[i] = -1;
    }

    if (k < n * m) {
        for (int i = 0; i < k / n; ++i) {
            for (int j = 0; j < n; ++j) {
                windows[j].push_back({i * n + j, customers[i * n + j]});
            }
        }
        for (int i = k / n * n; i < k; ++i) {
            windows[i - k / n * n].push_back({i, customers[i]});
        }
    }
    else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                windows[j].push_back({i * n + j, customers[i * n + j]});
            }
        }
    }

    int e = n * m;
    int now_time = START_TIME;
    printInfo();
    do {
        int which = -1;
        int shortest_time = 1000000;
        for (int i = 0; i < n; ++i) {
            if (!windows[i].empty()) {
                if (shortest_time > windows[i].front().second) {
                    which = i;
                    shortest_time = windows[i].front().second;
                }
            }
        }

        if (which >= 0) {
            now_time += shortest_time;
            done[windows[which].front().first] = now_time;
            windows[which].pop_front();
            if (e < k) {
                windows[which].push_back({e, customers[e]});
                ++e;
            }
            for (int i = 0; i < n; ++i) {
                if (i == which) continue;
                if (windows[i].size() != 0) {
                    windows[i].front().second -= shortest_time;
                    if (windows[i].front().second == 0) {
                        done[windows[i].front().first] = now_time;
                        windows[i].pop_front();
                        if (e < k) {
                            windows[i].push_back({e, customers[e]});
                            ++e;
                        }
                    }
                }
            }
            if (now_time >= END_TIME) {
                printInfo();
                break;
            }
        } else {
            if (e < k) {
                windows[0].push_back({e, customers[e]});
                ++e;
            } else {
                break;
            }
        }

        printInfo();
    } while (true);

    while (q--) {
        int b;
        cin >> b;
        b--;
        if (done[b] > END_TIME || done[b] < 0) {
            cout << "Sorry" << endl;
        }
        else {
            auto t = getTime(done[b]);
            cout << setfill('0') << setw(2) << t.first << setw(1) << ':' <<
                setw(2) << t.second << endl;
        }
    }

    return 0;
}
