#include <bits/stdc++.h>
using namespace std;

int mergenCount(vector<int>& a, int left, int mid, int right) {
    int count = 0;

    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && a[i] > 2 * a[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    vector<int> temp;
    int i = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        } else {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = left; k <= right; k++) {
        a[k] = temp[k - left];
    }

    return count;
}

int countDangerousPairs(vector<int>& a, int left, int right) {
    if (left >= right)
        return 0;

    int mid = (left + right) / 2;

    int count = 0;
    count += countDangerousPairs(a, left, mid);
    count += countDangerousPairs(a, mid + 1, right);
    count += mergenCount(a, left, mid, right);

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    cout << countDangerousPairs(students, 0, n - 1) << endl;
    return 0;
}
