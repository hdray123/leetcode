#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> dev(3,0);
        sort(nums.begin(),nums.end());
        for(int medium=1;medium<nums.size()-1;++medium){
            int start=0;
            int end=nums.size()-1;
            while(start<medium && medium<end){
                if((nums[start]+nums[medium]+nums[end])==0){
                    dev[0]=nums[start];
                    dev[1]=nums[medium];
                    dev[2]=nums[end];
                    result.push_back(dev);
                    break;
                }
                if((nums[start]+nums[medium]+nums[end])<0){
                    ++start;
                } else {
                    --end;
                }

            }
       }
        return result;
        }
int main() {
    vector<int> nums(6);
    vector<vector<int>> result;
    for (int i = 0; i <6 ; ++i) {
        cin>>nums[i];
    }
    
    result=threeSum(nums);
    for (vector<vector<int>>::iterator j = result.begin(); j < result.end() ; ++j) {
        for (vector<int>::iterator i= (*j).begin();  i<(*j).end() ; ++i) {
            cout<<*i;

        }
        cout<<endl;
        
    }
    return 0;
}