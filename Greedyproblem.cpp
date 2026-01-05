#include <bits/stdc++.h>
using namespace std;
bool canplant(vector<int> &flowerbed, int n){
int Size = flowerbed.size();
for(int i=0;i<Size;i++){
        if (flowerbed[i]==0){
    bool leftside = (i==0)||(flowerbed[i-1]==0);
    bool rightside = (i==Size-1)||(flowerbed[i+1==0]);
    if (leftside&&rightside){
        flowerbed[i]=1;
        n--;
        if(n<=0)return true;
    }
}
}
return false;
}
int main(){
    vector<int> flowerbed;
    int n;
    cout<<"flowerbed plot numbers:";
    cin>>n;
    cout<<"flowerbed plot arrngement:";
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        flowerbed.push_back(a);
    }
    cout<<"number of flowers: ";
    int b;
    cin >> b;

    if (canplant(flowerbed,b)){
        cout<<"True";
    }else {
        cout<<"False";
    }
return 0;
}
