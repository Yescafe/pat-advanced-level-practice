#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, string> en {
    {0, "zero"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
    {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
};

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    for (const auto& c : str) {
        sum += c - '0';
    }
    string sum_str = to_string(sum);
    bool first = true;
    for (const auto& c : sum_str) {
        if (first) first = false;
        else cout << " ";
        cout << en[c - '0'];
    }
    cout << endl;
    return 0;
}
