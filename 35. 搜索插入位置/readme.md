#35.搜索插入位置

题目描述

>给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。如果没有，返回到它将会被按顺序插入的位置。

> 你可以假设在数组中无重复元素。

 

**案例 1:**

```
输入: [1,3,5,6], 5
输出: 2
```

 

**案例 2:**

```
输入: [1,3,5,6], 2
输出: 1
```

 

**案例 3:**

```
输入: [1,3,5,6], 7
输出: 4
```

 

**案例 4:**

```
输入: [1,3,5,6], 0
输出: 0
```

代码

```c++
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int medium=(s+e)/2;
            if(nums[medium]==target) return medium;
            if(nums[medium]<target && medium==e) return medium+1;
            if(nums[medium]<target && nums[medium+1]>target) return medium+1;
            if(nums[medium]>target && medium==s) return medium;
            if(nums[medium]>target && nums[medium-1]<target) return medium;
            if(target<nums[medium]) e=medium-1;
            if(target>nums[medium]) s=medium+1;
        }
    }
```

