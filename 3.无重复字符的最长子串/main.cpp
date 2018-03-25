#include <iostream>
#include <string>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start) {
            cout << s[i] << dict[s[i]] << "\n";
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}
int main() {
    int max_length=0;
    string a;
    cin>>a;
    max_length=lengthOfLongestSubstring(a);
    cout<<max_length;

    return 0;
}