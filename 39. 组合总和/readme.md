#39.组合总和

题目：

给**一组**候选数字**（C）（没有重复）**并给一个目标数字**（T）**，找出 **\*C*** 中所有唯一的组合使得它们的和为 **\*T***。

可以从 **C** 无限次数中选择**相同**的数字。

**说明：**

- 所有数字（包括目标）都是正整数。
- 解集合中没有相同组合。

 

例如，给一个候选集合 `[2, 3, 6, 7]` 并且目标为 `7`，
一个解的集合为：

```
[
  [7],
  [2, 2, 3]
]
```

------

代码：

```c++
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        int begin=0;
        sum(candidates,target,combination,result,begin);
        return result;
        
    }
private:
    void sum(vector<int> &candidates,int target,vector<int>& combination,vector<vector<int>>& result,int begin){
        if(target==0){
            result.push_back(combination);
            return;
        }
        for(int i=begin;i<candidates.size() && target>=candidates[i];++i){
            begin=i;
            combination.push_back(candidates[i]);
            sum(candidates,target-candidates[i],combination,result,begin);
            combination.pop_back();
        }
        
    }
```

思路：

先对序列进行排序，然后用target从小到大遍历减去。应为可以减去一样的元素多次，所以在下一个循环开始也是从原来的位置开始。如果target减到等于0.就说明是需要的组合。