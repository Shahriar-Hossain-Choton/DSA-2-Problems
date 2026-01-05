#include <bits/stdc++.h>
using namespace std;

int countEven(vector<int> &arr, int left, int right) {

    if (left == right) {
        if (arr[left] % 2 == 0)
            return 1;
        else
            return 0;
    }

    int mid = (left + right) / 2;

    int leftCount = countEven(arr, left, mid);
    int rightCount = countEven(arr, mid + 1, right);

    return leftCount + rightCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = countEven(arr, 0, n - 1);
    cout << result << endl;

    return 0;
}
