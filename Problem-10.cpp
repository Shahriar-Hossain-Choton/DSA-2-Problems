#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int,int>> &arr, int left, int mid, int right, vector<int> &ans)
{
    vector<pair<int,int>> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i].first <= arr[j].first)
        {

            ans[arr[i].second] += (j - mid - 1);
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    {
        ans[arr[i].second] += (j - mid - 1);
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
        arr[k] = temp[k - left];
}

void mergeSort(vector<pair<int,int>> &arr, int left, int right, vector<int> &ans)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, ans);
    mergeSort(arr, mid + 1, right, ans);
    merge(arr, left, mid, right, ans);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> ans(n, 0);
    vector<pair<int,int>> arr;

    for (int i = 0; i < n; i++)
        arr.push_back({nums[i], i});

    mergeSort(arr, 0, n - 1, ans);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
