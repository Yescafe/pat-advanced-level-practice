#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> cards, next(54);
    cards.reserve(54);
    for (const auto& c : {'S', 'H', 'C', 'D'}) {
        for (int i = 1; i <= 13; ++i) {
            cards.push_back(string(1, c) + to_string(i));
        }
    }
    cards.push_back("J1");
    cards.push_back("J2");

    int k;
    cin >> k;
    vector<int> ord(54);
    for (int i = 0; i < 54; ++i) {
        cin >> ord[i];
        --ord[i];
    }

    for (int t = 0; t < k; ++t) {
        for (int i = 0; i < 54; ++i) {
            next[ord[i]] = cards[i];
        }
        copy(next.begin(), next.end(), cards.begin());
    }

    for (int i = 0; i < 54; ++i) {
        if (i != 0) cout << ' ';
        cout << cards[i];
    }

    return 0;
}

