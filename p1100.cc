#include <chrono>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

#define LEN(ARR) (sizeof(ARR) / sizeof(ARR[0]))

string numbers[] {
    "tret", "jan", "feb", "mar",
    "apr", "may", "jun", "jly", "aug",
    "sep", "oct", "nov", "dec",
};

string higher[] {
    "tret", "tam", "hel", "maa",
    "huh", "tou", "kes", "hei", "elo",
    "syy", "lok", "mer", "jou",
};

int main()
{
    int n;
    cin >> n;
    string line;
    while (n) {
        getline(cin, line);
        while (isspace(line.back())) line.pop_back();
        if (line.empty()) continue;
        n--;
        if (isdigit(line[0])) {
            int l = stoi(line);
            string h, n;
            h = higher[l / 13];
            n = numbers[l % 13];
            if (l / 13 == 0) {
                cout << n << endl;
            }
            else {
                cout << h;
                if (l % 13 != 0)
                    cout << " " << n;
                cout << endl;
            }
        } else {
            stringstream ss;
            ss << line;
            string word;
            int n = 0;
            while (ss >> word) {
                auto fnd1 = find(numbers, numbers + LEN(numbers), word);
                if (fnd1 != numbers + LEN(numbers)) {
                    n += (fnd1 - numbers);
                    continue;
                }
                auto fnd2 = find(higher, higher + LEN(higher), word);
                if (fnd2 != higher + LEN(higher)) {
                    n += (fnd2 - higher) * 13;
                    continue;
                }
            }
            cout << n << endl;
        }
    }
    return 0;
}
