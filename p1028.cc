#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
    string id;
    string name;
    int grade;
};
vector<Record> sheet;

int main()
{
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; ++i) {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        sheet.push_back({id, name, grade});
    }

    switch (c) {
        case 1:
            sort(sheet.begin(), sheet.end(), [](const Record& a, const Record& b) {
                        return a.id < b.id;
                    });
            break;
        case 2:
            sort(sheet.begin(), sheet.end(), [](const Record& a, const Record& b) {
                        if (a.name != b.name) {
                            return a.name < b.name;
                        }
                        else {
                            return a.id < b.id;
                        }
                    });
            break;
        case 3:
            sort(sheet.begin(), sheet.end(), [](const Record& a, const Record& b) {
                        if (a.grade != b.grade) {
                            return a.grade < b.grade;
                        }
                        else {
                            return a.id < b.id;
                        }
                    });
            break;
        default:
            break;
    }

    for (auto& r : sheet) {
        cout << r.id << ' ' << r.name << ' ' << r.grade << endl;
    }

    return 0;
}
