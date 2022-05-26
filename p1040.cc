#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
#define N 1005

bool isSymm[N][N];

int main()
{
    string line;
    getline(cin, line);

    int n = line.size();
    int res = 1;
    memset(isSymm, 0, sizeof(isSymm));
    for (int i = 0; i < n; ++i) {
        isSymm[i][i] = true;
        if (i != 0 && line[i - 1] == line[i]) {
            isSymm[i - 1][i] = true;
            res = 2;
        }
    }

    for (int d = 3; d <= n; ++d) {
        for (int i = 0; i + d - 1 < n; ++i) {
            if ((isSymm[i][i + d - 1] = isSymm[i + 1][i + d - 2] && (line[i] == line[i + d - 1])) == true) {
                res = max(res, d);
            }
        }
    }
    cout << res << endl;

    return 0;
}
