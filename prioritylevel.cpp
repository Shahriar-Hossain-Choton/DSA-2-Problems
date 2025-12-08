/*In Dhaka’s emergency control center, each ambulance case is assigned a priority level.
The higher the number, the more critical the case.
Your task:
1.  Read n priority levels
2.  Store them in a vector<int>
3.  Sort them in descending order
4.  Print the top 3 highest priorities
If fewer than 3 exist, print only the available ones
Input Format:
First line: integer n
Next Line: n emergency priority values
Output:
Top 3 emergency levels in descending order*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<string> name;

    cout << "Whats the size?" << endl;
    cin >> n;

    cout << "What are the elements?" << endl;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        name.push_back(a);
    }

    set<string> s(name.begin(), name.end());
    name.assign(s.begin(), s.end());

    for (int i = 0; i < name.size(); i++) {
        cout << name[i] << endl;
    }

    return 0;
}
