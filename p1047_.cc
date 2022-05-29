#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

vector<vector<string>> course;

int main()
{
    int ns, nc;
    cin >> ns >> nc;
    course.assign(nc, {});

    for (int i = 0; i < ns; ++i) {
        string id;
        int nsc;
        cin >> id >> nsc;
        for (int j = 0; j < nsc; ++j) {
            int c;
            cin >> c;
            course[c - 1].push_back(id);
        }
    }

    for (int i = 0; i < nc; ++i) {
        cout << i + 1 << " " << course[i].size() << endl;
        sort(course[i].begin(), course[i].end());
        for (auto& st : course[i]) {
            cout << st << endl;
        }
    }

    return 0;
}
