#include <bits/stdc++.h>
using namespace std;
int main (){
  vector<int> codes;
  int n;
  cout << "Number of codes:" << endl;
  cin >> n;
  cout << "What are the Codes?"<<endl;
  int temp;
  for(int i = 0; i<n;i++){
    cin >> temp;
    codes.push_back(temp);
  }
  sort(codes.begin(),codes.end(),greater<int>());
  for(int i = 0; i<3;i++){
    cout<<codes[i]<<" ";
  }
  return 0;
}

