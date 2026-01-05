#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u');
}

int countVowels(string &s, int left, int right) {

    if (left == right) {
        if (isVowel(s[left]))
            return 1;
        else
            return 0;
    }

    int mid = (left + right) / 2;

    int leftCount = countVowels(s, left, mid);
    int rightCount = countVowels(s, mid + 1, right);

    return leftCount + rightCount;
}

int main() {
    string s;
    getline(cin, s);

    int result = countVowels(s, 0, s.length() - 1);
    cout << result << endl;

    return 0;
}
