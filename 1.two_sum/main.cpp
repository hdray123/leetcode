#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;
int main() {
    vector<int> num;
    vector<int> result(2);
    num.push_back(2); num.push_back(7);num.push_back(11);num.push_back(9);
    int target=9;
    unordered_map<int,int> valuemap;
    for(int i=0;i<num.size();i++){
        int value=target-num[i];
        if(valuemap.find(value)!=valuemap.end()){
            result[0]=valuemap[value];
            result[1]=i;
            break;
        } else{
            if(valuemap.find(num[i])==valuemap.end()){
                valuemap[num[i]]=i;
            }
        }
    }

    cout<<result[0]<<result[1]<<endl;



}