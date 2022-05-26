#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    string id;
    int grade;
};

vector<Student> male, female;

bool cmp(const Student& a, const Student& b) {
    return a.grade < b.grade;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string name, id;
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        switch (gender) {
            case 'M':
                male.push_back({name, id, grade});
                break;
            case 'F':
                female.push_back({name, id, grade});
                break;
        }
    }

    sort(male.begin(), male.end(), cmp);
    sort(female.begin(), female.end(), cmp);

    if (!female.empty()) {
        cout << female.back().name << " " << female.back().id << endl;
    }
    else {
        cout << "Absent" << endl;
    }
    if (!male.empty()) {
        cout << male.front().name << " " << male.front().id << endl;
    }
    else {
        cout << "Absent" << endl;
    }

    if (female.empty() || male.empty()) {
        cout << "NA" << endl;
    }
    else {
        cout << female.back().grade - male.front().grade << endl;
    }

    return 0;
}
