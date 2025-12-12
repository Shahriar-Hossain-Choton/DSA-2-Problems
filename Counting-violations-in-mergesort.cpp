/*The UIU library arranges books in ascending order of their serial numbers.
 One day, a student accidentally shuffled a shelf.
 Now, some books are placed incorrectly, meaning a larger serial number appears before a 
smaller one.
A “violation” occurs whenever such a wrong order appears.
Using Divide & Conquer, compute the total number of violations.
(This matches students’ understanding of inversion count with story context.)
Input:
First line: n
Second line: n space-separated serial numbers
Output:
Total number of violations.
Example:
Input:
 5
 40 32 50 30 25
Output:
 8*/
#include <bits/stdc++.h>
using namespace std;
int MergeAndCount(vector<int> &a,int left,int mid,int right){
    vector <int> merged;
    int i= left;
    int j=mid+1;
    int voilations = 0;

    while(i<=mid && j<=right){

        if (a[i]<=a[j]){
        merged.push_back(a[i]);
        i++;
        }else {
            voilations +=(mid-i+1);
            merged.push_back(a[j]);
            j++;
        }

    }
    while(i<=mid){
        merged.push_back(a[i]);
        i++;
    }
    while(j<=right){
        merged.push_back(a[j]);
        j++;
    }
    int index = 0;
    for(int k= left; k<=right;k++){
        a[k] = merged[index];
        index++;
    }

    return voilations;
}
int CountViolations(vector<int> &a, int left, int right){

    if(left>=right){
        return 0;
    }

    int mid = (left+right)/2;

    int leftcount = CountViolations(a,left,mid);
    int rightcount = CountViolations(a,mid+1,right);
    int mergercount = MergeAndCount(a,left,mid,right);

    return leftcount+rightcount+mergercount;

}
int main(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i =0;i<n;i++){
        int a;
        cin >> arr[i];
    }
    int Count=CountViolations(arr,0,n-1);
    cout << Count;

return 0;
}
