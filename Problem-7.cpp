#include <bits/stdc++.h>
using namespace std;

pair<int,int> largestPair(vector<int> &arr, int left, int right) {
    if (left == right) {
        return {arr[left], INT_MIN};
    }

    if (right == left + 1) {
        if (arr[left] > arr[right])
            return {arr[left], arr[right]};
        else
            return {arr[right], arr[left]};
    }

    int mid = (left + right) / 2;

    pair<int,int> L = largestPair(arr, left, mid);
    pair<int,int> R = largestPair(arr, mid + 1, right);

    int firstMax, secondMax;

    if (L.first > R.first) {
        firstMax = L.first;
        secondMax = max(L.second, R.first);
    } else {
        firstMax = R.first;
        secondMax = max(R.second, L.first);
    }

    return {firstMax, secondMax};
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pair<int,int> result = largestPair(arr, 0, n - 1);

    cout << "Largest pair: " << result.first << " " << result.second << endl;

    return 0;
}
