#include <bits/stdc++.h>
using namespace std;

int countInRange(vector<int> &arr, int left, int right, int num) {
    int cnt = 0;
    for (int i = left; i <= right; i++) {
        if (arr[i] == num)
            cnt++;
    }
    return cnt;
}

int majorityElement(vector<int> &arr, int left, int right) {
    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    int leftMajor = majorityElement(arr, left, mid);
    int rightMajor = majorityElement(arr, mid + 1, right);

    if (leftMajor == rightMajor)
        return leftMajor;

    int leftCount = countInRange(arr, left, right, leftMajor);
    int rightCount = countInRange(arr, left, right, rightMajor);

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << majorityElement(arr, 0, n - 1) << endl;

    return 0;
}
