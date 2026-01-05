#include <bits/stdc++.h>
using namespace std;
int largestperimeter(vector<int> &arr){
    sort(arr.begin(),arr.end());
    for(int i=arr.size()-1;i>=2;i--){
    int a = arr[i-2];
    int b = arr[i-1];
    int c = arr[i];
    if(a+b>c){
        return a+b+c;
    }
    }
    return 0;
}
int main(){
    int n;
    cin >> n;
vector <int> triangle;
for(int i=0;i<3;i++){
    int a;
    cin >> a;
    triangle.push_back(a);
}
int result = largestperimeter((triangle));
cout<<result;
return 0;
}
