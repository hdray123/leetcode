```c++
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
```

