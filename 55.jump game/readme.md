# 55.跳跃游戏

题目：

给定一个非负整数数组，您最初位于数组的第一个索引处。

数组中的每个元素表示您在该位置的最大跳跃长度。

确定是否能够到达最后一个索引。

**示例：**
A = `[2,3,1,1,4]`，返回 `true`。

A = `[3,2,1,0,4]`，返回 `false`。

代码：

```c++
bool canJump(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int reach=0;
        while(start<n && start<=reach){
            reach=max(start+nums[start],reach);
            start++;
        }
        return start==n;
    }
```

