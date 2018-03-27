# 15.3sum

### 题目描述

>给定一个包含 *n* 个整数的数组 *S*，是否存在属于 *S* 的三个元素 *a，b，c *使得 *a + b + c = *0 ？找出所有不重复的三个元素组合使三个数的和为零。

**注意：**结果不能包括重复的三个数的组合。

```
例如, 给定数组 S = [-1, 0, 1, 2, -1, -4]，

一个结果集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```



代码

```c++
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
```

#### 算法思路

先对无序vector进行排序 sort(vector.beign(),vector.end())

然后确定medium数遍历整个vector然后从vector的头和尾不断向中间靠拢，三个数的和如果大于0则end—，小于0则start++，等于0则将[start,medium,end]保存到二维的vector中，时间复杂度n的平方。

