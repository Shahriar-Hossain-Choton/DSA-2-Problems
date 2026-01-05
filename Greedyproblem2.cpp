#include <bits/stdc++.h>
using namespace std;
int balancedstringnumber(string s){
                         int lcount=0;
                         int rcount=0;
                         int answercount=0;

                         for(char c : s){
                            if(c=='L'){
                                lcount++;
                            }else{
                                rcount++;
                            }
                            if(lcount==rcount){
                                answercount++;
                            }
                         }
                         return answercount;
}
int main(){
    string s;
    cin >> s;
    cout << balancedstringnumber(s);
return 0;
}
