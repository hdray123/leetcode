#53. 最大子序和

题目：

> 给定一个序列（至少含有 1 个数），从该序列中寻找一个连续的子序列，使得子序列的和最大。

> 例如，给定序列 `[-2,1,-3,4,-1,2,1,-5,4]`，

> 连续子序列 `[4,-1,2,1]` 的和最大，为 `6`。

代码：

```c++
int maxSubArray(vector<int>& nums) {
        int local_max=nums[0];
        int global_max=nums[0];
        for(int i=1;i<nums.size();++i){
            local_max=max((local_max+nums[i]),nums[i]);
            global_max=max(local_max,global_max);
        }
        return global_max;
    }
```

