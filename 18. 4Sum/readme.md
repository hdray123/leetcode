# 18.4sum

### 没有ac

代码：

```c++
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> dev(4);
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return result;
        for(int i=1;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                int start=0;
                int end=nums.size()-1;
                while(start<i && j<end){
                    
                    if(nums[start]==nums[start+1] && (start+1)<i){
                        start++;
                        continue;
                    }
                    if(nums[end]==nums[end-1] && (end-1)>j){
                        end--;
                        continue;
                    }
                    int sum=nums[start]+nums[i]+nums[j]+nums[end];
                    if(sum==target){
                        dev[0]=nums[start];
                        dev[1]=nums[i];
                        dev[2]=nums[j];
                        dev[3]=nums[end];
                        result.push_back(dev);
                        start++;
                        
                    }
                    if(sum<target){
                        start++;
                    }else{
                        end--;
                    }
                }      
            }
        }
        return result;
    }
```

输出二维vector中有重复vector 其他与3_sum差不多。