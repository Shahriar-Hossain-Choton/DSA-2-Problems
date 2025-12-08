#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    vector<string> name;
    cout << "Whats the size?"<<endl;
    cin >> n;
    cout << "What are the elements?:"<<endl;
    for(int i= 0;i<n;i++){
        string a;
        cin >> a;
        name.push_back(a);
    }
    sort(name.begin(),name.end());
    set<string> s(name.begin(),name.end());
    name.assign(s.begin(),s.end());
    for(int i= 0;i<name.size();i++){
        cout<<name[i]<<endl;
    }
}
