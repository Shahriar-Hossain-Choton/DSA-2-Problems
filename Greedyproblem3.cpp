#include<bits/stdc++.h>>
using namespace std;
bool ispalindrome(string s,int l, int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        r--;
        l++;
    }
    return true;
}
bool validpalindome(string s){
    int l=0;
    int r=s.size()-1;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else {
            return ispalindrome(s,l+1,r)||ispalindrome(s,l,r-1);
        }
    }
    return true;
}
int main(){
    string s;
    cin >> s;

    if(validpalindome(s)){
        cout<<"True";
    }else {
    cout<<"False";
    }
return 0;
}
