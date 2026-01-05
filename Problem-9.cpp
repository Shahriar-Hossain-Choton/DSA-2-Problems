#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int l, int r,
           int &best, int &prefix, int &suffix,
           int &total, bool &hasNeg) {

    if (l == r) {
        if (arr[l] >= 0) {
            best = prefix = suffix = total = arr[l];
            hasNeg = false;
        } else {
            best = prefix = suffix = total = 0;
            hasNeg = true;
        }
        return;
    }

    int mid = (l + r) / 2;

    int bestL, preL, sufL, sumL;
    int bestR, preR, sufR, sumR;
    bool negL, negR;

    solve(arr, l, mid, bestL, preL, sufL, sumL, negL);
    solve(arr, mid + 1, r, bestR, preR, sufR, sumR, negR);

    total = sumL + sumR;

    hasNeg = negL || negR;

    if (!negL)
        prefix = sumL + preR;
    else
        prefix = preL;

    if (!negR)
        suffix = sumR + sufL;
    else
        suffix = sufR;

    best = max({
        bestL,
        bestR,
        sufL + preR
    });
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int best, prefix, suffix, total;
    bool hasNeg;

    solve(arr, 0, n - 1, best, prefix, suffix, total, hasNeg);

    cout << best << endl;
    return 0;
}
