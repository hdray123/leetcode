#34.搜索范围

题目描述：

给定一个已经升序排序的整形数组，找出给定目标值的开始位置和结束位置。

你的算法时间复杂度必须是 *O*(log *n*) 级别。

如果在数组中找不到目标，返回 `[-1, -1]`。

**例如:**
给出 `[5, 7, 7, 8, 8, 10]` 和目标值 8，
返回 `[3, 4]`。

代码：

```c++
 vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int s=0;
        int e=nums.size()-1;
        int i=-1;
        while(s<=e){
            int medium=(s+e)/2;
            if(target==nums[medium]){
                i=medium;
                break;
            }
            if(target>nums[medium]){
                s=medium+1;
            }else{
                e=medium-1;
            }
        }
        if(i==-1){
            return result;
        }
        int m=i;
        while(nums[m+1]==target && m<nums.size()-1){
            m++;
        }
        while(nums[i-1]==target && i>0){
            i--;
        }
        result[0]=i;
        result[1]=m;
        return result;
        
        
        
    }
```

思路：排序队列二分控制时间复杂度为log(n)