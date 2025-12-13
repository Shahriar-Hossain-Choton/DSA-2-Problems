/*UIU monitors the electricity consumption in each room every hour.
 A positive number means normal usage.
 A negative number indicates a sudden voltage drop or system error.
You must find the maximum sum of any continuous subarray that contains only non
negative values
 (using Divide and Conquer).
Input:
First line: n
Second line: n integers showing consumption values
Output:
Maximum sum of a safe (non-negative) subarray.
Example:
Input:
 10
 4 3 -2 6 8 1 -5 2 4 3
Output:
 15
 (from subarray 6 8 1*/
#include <bits/stdc++.h>
using namespace std;
int maxCrossSum(vector<int> &a,int l,int m,int r){
    int sum = 0;
    int leftsum =0;

    for(int i=m;i>=l;i--){
        if(a[i]<0) break;
        sum += a[i];
        leftsum = max(leftsum, sum);
    }

    sum=0;
    int rightsum = 0;

    for(int i = m+1;i<=r;i++){
       if (a[i]<0) break;
       sum +=a[i];
       rightsum = max(rightsum, sum);
    }
    return leftsum + rightsum;
}

int maxsafesum(vector<int> &a,int l,int r){
    if(l==r){
        if(a[l]>=0){
            return a[l];
        }else {
            return 0;
        }
    }
    int m = (l+r)/2;

    int leftmax = maxsafesum(a,l,m);
    int rightmax = maxsafesum(a,m+1,r);
    int crossmax = maxCrossSum(a,l,m,r);

    return max({leftmax,rightmax,crossmax});
}
int main(){
    int n;
    cin >> n;

    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << maxsafesum(a,0,n-1) << endl;
return 0;
}
