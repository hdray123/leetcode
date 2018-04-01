#33.Search in Rotated Sorted Array

> 题目

假设按照升序排序的数组在预先未知的某个关键点上旋转。

（即 `0 1 2 4 5 6 7` 将变成 `4 5 6 7 0 1 2`）。

给你一个目标值来搜索，如果数组中存在这个数则返回它的索引，否则返回 -1。

你可以假设数组中不存在重复。

代码：

```c++
int search(vector<int>& nums, int target) {
	int l=0,r=nums.size()-1;
    while(l<=r){
        int medium=(l+r)/2;
        if(nums[medium]==target) return medium;
        if(nums[medium]<nums[r]){
            if(target>nums[medium] && target<=nums[r])
                l=medium+1;
            else
                r=medium-1;
        }else{
            if(target<nums[medium] && target>=nums[l])
                r=medium-1;
            else
                l=medium+1;
        }
    }
    return -1;
}
```
思想：

一个升序数组在某个关键点上选转。如`0->1->2->4->5->6->7`变成`4->5->6->7->0->1->2`说明是在0和7中有断点，4->7是升序 0->2也是升序。如果nms[medium]<nums[r]说明断点在medium左边，则medium-r为升序，相反则在右边，l-medium为升序。寻找target则可以使用二分法。算法复杂度应该为log(n).