#include <iostream>
#include <algorithm>
using namespace std;
#define N 10010

int arr[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto max_elem = max_element(arr, arr + n);
    if (*max_elem < 0) {
        cout << 0 << " " << arr[0] << " " << arr[n - 1] << endl;
        return 0;
    }

    int sum = 0, max_sum = -1;
    int start = 0;
    int max_sum_start = 0, max_sum_finish = n - 1;
    for (int i = 0; i < n; ++i) {
        if (sum + arr[i] < 0) {
            sum = 0;
            start = i + 1;
            continue;
        }
        sum += arr[i];
        if (sum > max_sum) {
            max_sum = sum;
            max_sum_start = start;
            max_sum_finish = i;
        }
    }

    cout << max_sum << " " << arr[max_sum_start] << " " << arr[max_sum_finish] << endl;
    return 0;
}
