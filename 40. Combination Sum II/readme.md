#40.Combination Sum II

题目：

给定候选号码数组 (**C**) 和目标总和数 (**T**)，找出 **C** 中候选号码总和为 **T** 的所有唯一组合。

**C** 中的每个数字只能在组合中使用**一次**。

**注意:**

- 所有数字（包括目标）都是正整数。
- 解决方案集不能包含重复的组合。

 

例如，给定候选集合 `[10, 1, 2, 7, 6, 1, 5]` 和目标总和数 `8`，
可行的集合是：

```
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
```

```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        int begin=-1;
        sum(candidates,result,combination,begin,target);
        return Remove_Repeat_vector(result);
    }
private:
    void sum(vector<int>& candidates,vector<vector<int>>& result,vector<int>& combination,int begin,int target){
        if(target==0){
            result.push_back(combination);
            return;
        }
        for(int i=begin+1;i<candidates.size() && target>=candidates[i];++i){
            combination.push_back(candidates[i]);
            sum(candidates,result,combination,i,target-candidates[i]);
            combination.pop_back();
            
        }
    }
    vector<vector<int>> Remove_Repeat_vector(vector<vector<int>>& result){
        vector<vector<int>> no_rep_result;
        int j;
        for(int i=0;i<result.size();++i){
            for(j=0;j<no_rep_result.size();++j){
                if(result[i]==no_rep_result[j]){
                    break;
                }
            }
            if(j==no_rep_result.size()){
                no_rep_result.push_back(result[i]);
            }
        }
        return no_rep_result;
    }
};
```

思考：

跟上一题一样只是不能重复使用元素所以每次递归都是从原来的+1如： `i=begin+1`

写了个去除二维vector中重复vector的函数Remove_Repeat_vector(vector<vector<int>>);

