#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<string, string>> svec;
    for (int i = 0; i < n; ++i) {
        string team_name, password;
        cin >> team_name >> password;
        string new_password = password;
        for (auto& c : new_password) {
            switch (c) {
                case '1':
                    c = '@';
                    break;
                case '0':
                    c = '%';
                    break;
                case 'l':
                    c = 'L';
                    break;
                case 'O':
                    c = 'o';
                    break;
            }
        }
        if (new_password != password) {
            svec.push_back({team_name, new_password});
        }
    }

    if (svec.empty()) {
        if (n == 1) {
            cout << "There is " << n << " account and no account is modified" << endl;
        }
        else {
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
        return 0;
    }
    cout << svec.size() << endl;
    for (auto& s : svec) cout << s.first << " " << s.second << endl;

    return 0;
}
