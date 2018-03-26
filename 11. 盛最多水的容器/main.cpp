#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a;
    cin>>a;
    int max_length=0,start=-1;
    vector<int> map(256,-1);
    for (int i = 0; i <a.length() ; ++i) {
        if(map[a[i]]>start){
            start=map[a[i]];
        }
        map[a[i]]=i;
        max_length=max(max_length,i-start);
    }
    cout<<max_length;
    return 0;
}