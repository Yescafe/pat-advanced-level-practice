#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
using ll = long long;

struct Student {
    string id;
    int score;
    int location_number;
    int local_rank;
    int final_rank;
    Student() = default;
    Student(string id, int score, int location_number, int local_rank = 0, int final_rank = 0)
        : id(id), score(score), location_number(location_number), local_rank(local_rank),
          final_rank(final_rank) {}
};

vector<Student> ranks;

bool cmp(const Student& a, const Student& b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}

int main()
{
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        int nn;
        cin >> nn;
        vector<Student> local;
        local.reserve(nn);
        for (int i = 0; i < nn; ++i) {
            string id;
            int score;
            cin >> id >> score;
            local.push_back({id, score, k});
        }
        sort(local.begin(), local.end(), cmp);
        for (int i = 0; i < nn; ++i) {
            if (i == 0) local[i].local_rank = 1;
            else {
                if (local[i].score == local[i - 1].score) {
                    local[i].local_rank = local[i - 1].local_rank;
                }
                else {
                    local[i].local_rank = i + 1;
                }
            }
        }

        for (const auto& l : local) {
            ranks.push_back(l);
        }
    }

    sort(ranks.begin(), ranks.end(), cmp);
    int size = ranks.size();
    for (int i = 0; i < size; ++i) {
        if (i == 0) ranks[i].final_rank = 1;
        else {
            if (ranks[i].score == ranks[i - 1].score) {
                ranks[i].final_rank = ranks[i - 1].final_rank;
            }
            else {
                ranks[i].final_rank = i + 1;
            }
        }
    }

    cout << size << endl;
    for (auto& s : ranks) {
        cout << s.id << ' ' << s.final_rank << ' ' << s.location_number << ' ' << s.local_rank << endl;
    }

    return 0;
}
