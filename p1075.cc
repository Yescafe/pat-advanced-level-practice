#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int n, k, t;

struct Student {
    int id;
    vector<int> problem;
    int total;
    bool shown;
    int rank;
    Student() : id{0}, problem(k, -1), total{0}, shown{false}, rank{0} {}
};

int main()
{
    cin >> n >> k >> t;
    vector<Student> student(n + 1, Student());
    for (int i = 1; i <= n; ++i) {
        student[i].id = i;
    }

    vector<int> full(k, 0);
    for (int i = 0; i < k; ++i) {
        cin >> full[i];
    }

    for (int _ = 0; _ < t; ++_) {
        int id;
        int problem_id, score;
        cin >> id >> problem_id >> score;
        if (score == -1) {
            if (student[id].problem[problem_id - 1] < 0) {
               student[id].problem[problem_id - 1] = 0;
            }
            continue;
        }
        else {
            student[id].shown = true;
            if (score > student[id].problem[problem_id - 1]) {
                if (student[id].problem[problem_id - 1] < 0) {
                    student[id].total += score;
                }
                else {
                    student[id].total = student[id].total - student[id].problem[problem_id - 1] + score;
                }
                student[id].problem[problem_id - 1] = score;
            }
        }
    }

    sort(student.begin() + 1, student.end(), [&](const Student& a, const Student& b) {
                if (a.total != b.total) {
                    return a.total > b.total;
                }
                int pref_a = 0, pref_b = 0;
                for (int i = 0; i < k; ++i) {
                    if (full[i] == a.problem[i]) {
                        ++pref_a;
                    }
                    if (full[i] == b.problem[i]) {
                        ++pref_b;
                    }
                }
                if (pref_a != pref_b) {
                    return pref_a > pref_b;
                }
                else {
                    return a.id < b.id;
                }
            });

    int prev = -1;
    for (int i = 1; i < student.size(); ++i) {
        if (!student[i].shown) continue;
        if (prev < 0) {
            printf("1");
        }
        else {
            if (student[i].total == student[prev].total) {
                printf("%d", student[prev].rank);
                student[i].rank = student[prev].rank;
            }
            else {
                printf("%d", i);
                student[i].rank = i;
            }
        }
        printf(" %.5d %d", student[i].id, student[i].total);
        for (int j = 0; j < k; ++j) {
            if (student[i].problem[j] < 0) {
                cout << " -";
                continue;
            }
            cout << ' ' << student[i].problem[j];
        }
        cout << endl;
        prev = i;
    }

    return 0;
}
