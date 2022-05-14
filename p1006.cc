#include <iostream>
#include <string>
using namespace std;

struct Time {
    int h, m, s;
    Time() = default;
    Time(int h, int m, int s) : h(h), m(m), s(s) {}
    friend bool operator<(const Time& lhs, const Time& rhs) {
        if (lhs.h != rhs.h) {
            return lhs.h < rhs.h;
        } else {
            if (lhs.m != rhs.m) {
                return lhs.m < rhs.m;
            } else {
                return lhs.s < rhs.s;
            }
        }
    }
    friend bool operator==(const Time& lhs, const Time& rhs) {
        return lhs.h == rhs.h && lhs.m == rhs.m && lhs.s == rhs.s;
    }
    friend bool operator>(const Time& lhs, const Time& rhs) {
        return !(lhs < rhs) && !(lhs == rhs);
    }
    friend istream& operator>>(istream& is, Time& t) {
        char coion;
        return (is >> t.h >> coion >> t.m >> coion >> t.s);
    }
};

int main()
{
    int n;
    cin >> n;
    string unlock_man, lock_man;
    Time unlock_time(100, 100, 100), lock_time(-1, -1, -1);
    for (int i = 0; i < n; ++i) {
        string name;
        Time start_time, end_time;
        cin >> name >> start_time >> end_time;
        if (start_time < unlock_time) {
            unlock_time = start_time;
            unlock_man = name;
        }
        if (end_time > lock_time) {
            lock_time = end_time;
            lock_man = name;
        }
    }
    cout << unlock_man << " " << lock_man << endl;
    return 0;
}
