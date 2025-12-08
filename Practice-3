#include <bits/stdc++.h>
using namespace std;
void removespace(vector <char> &a, int n){
    if(n<0) return;
    if(a[n] == ' '){
        a.erase(a.begin()+n);
    }
    removespace(a,n-1);
}
void tolowercase(vector <char> &a,int n){
    if(n<0)return;
    a[n]=tolower(a[n]);
    tolowercase(a,n-1);
}
bool palindrome(vector <char> &a , int first, int last){
    if(first>=last) return true;
    if(a[first]!=a[last]) return false;
     return palindrome(a,first+1,last-1);
}

int main(){
vector <char> a;
cout << "Whats the range ?:"<<endl;
int n;
cin >> n;
cout << "Whats the message ?:";
cin.ignore();
for(int i =0;i<n;i++){
    char c;
    cin.get(c);
    a.push_back(c);
}
removespace(a,n-1);
tolowercase(a,n-1);
if(palindrome(a,0,a.size()-1)){
    cout<<"YES"<<endl;
}else{
    cout<<"no"<<endl;
}

    return 0;
}
