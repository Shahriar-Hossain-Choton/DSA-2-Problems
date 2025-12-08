/*You arranged a technical workshop at UIU. Students wrote their names while entering the
room; however, some students wrote their names more than once.
You need to prepare the final attendance list where:
Duplicate names are removed
Names are printed in alphabetical order
Input Format:
First line: integer n
Next n lines: student names
Output:
Unique names in sorted order*/

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


