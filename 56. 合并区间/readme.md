#56.合并区间

题目：

给出一个区间的集合，请合并所有重叠的区间。

**示例：**
给出 `[1,3],[2,6],[8,10],[15,18]` ，
返回 `[1,6],[8,10],[15,18]` .

代码：

```c++
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}
};
```

想法：sort(begin,end,compare) compare为比较方法：a.start<b.start 说明是根据start升序排列的。