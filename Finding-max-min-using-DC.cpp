/*UIU cafeteria prints food tokens every morning.
 Each token contains an estimated waiting time in minutes.
However, due to a printing machine malfunction, the times are mixed up.
Your task is to use Divide and Conquer to find:
The minimum waiting time
The maximum waiting time
Input:
First line contains n, the number of tokens.
Second line contains n space-separated integers representing waiting times.
Output:
Print the minimum and maximum waiting times.
Example:
Input:
 8
 12 6 3 14 7 19 5 11
Output:
 Minimum = 3, Maximum = 19*/

#include <bits/stdc++.h>
using namespace std;
vector <int> Findmaxmin(vector<int> &arr,int first,int last){
    if(first == last){
        return {arr[first],arr[last]};
    }
    if(last==first+1){
        int mn = min(arr[first],arr[last]);
        int mx = max(arr[first],arr[last]);
        return {mn,mx};
    }

    int mid = (first+last)/2;

    vector <int> leftpart = Findmaxmin(arr,first,mid);
    vector <int> rightpart = Findmaxmin(arr,mid+1,last);

    int finalmin = min(leftpart[0],rightpart[0]);
    int finalmax = max(leftpart[1],rightpart[1]);

    return {finalmin,finalmax};
}
int main(){
    int n;
    cout<<"Whats the number of Tokens? :"<<endl;
    cin>>n;
    cout<<"What are the waiting times? :"<<endl;
    vector<int> arr;
    for(int i=0;i<n;i++){
            int in;
        cin >> in;
        arr.push_back(in);
    }
    vector<int> result = Findmaxmin(arr,0,arr.size()-1);
    cout<< "Minimum Waiting Time: "<<result[0]<<endl;
    cout<< "Maximum Waiting Time: "<<result[1];
return 0;
}
