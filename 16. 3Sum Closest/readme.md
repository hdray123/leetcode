# 16.3Sum Closest

题目：

>给定一个包括 n 个整数的数组 S，找出 S 中的三个整数使得他们的和与给定的数 target 最接近。返回这三个数的和。假定每组输入只存在一个答案。

```
例如，给定数组 S = {-1 2 1 -4}, 并且 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
```



代码：

```c++
int threeSumClosest(vector<int>& nums, int target) {
        int clost_number=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-1;++i){
            int start=0;
            int end=nums.size()-1;
            while(start<i && i<end){
                int sum=nums[start]+nums[i]+nums[end];
                if( abs(clost_number-target)>abs(sum-target)){
                    clost_number=nums[start]+nums[i]+nums[end];
                }
                if(sum==target) break;
                if(sum<target) start++;
                if(sum>target) end--;
            }
        }
        return clost_number;
    }
```

跟3_sum 差不多也是先去排序在中间数，然后根据三个数的sum跟target比较大小，大了end—（次次打成end++）小了start++；