# two_sum

> 题目描述：给定一个整数数列，找出其中和为特定值的那两个数。
>
> 你可以假设每个输入都只会有一种答案，同样的元素不能被重用。
>
> **示例:**
>
> ```
> 给定 nums = [2, 7, 11, 15], target = 9
>
> 因为 nums[0] + nums[1] = 2 + 7 = 9
> 所以返回 [0, 1]
> ```

vector数据类型与array数据类型区别：

array定义后空间固定，vector通过push_back增加，pop_back删除 ，可以通过vector.size()了解vector中含有元素数量。

unordered_map<int,int> map的数据类型，通过key找到value通过find() 找不到返回unordered_map.end().

####本题的思路是创建一个map，target-num_1=num_2，应为num_1和num_2都在vector列表中，在遍历vector列表的时候，算出（target-列表元素)的值在将值在map中寻找对应的key如果找到则说明差已经在前面出现过了并被存储到了map中 value对应的是那个num在vector的下标位置，如果没有找到则说明差应该在后面，所以讲num和i存入map。

```c++
if(valuemap.find(num[i])==valuemap.end()){
         valuemap[num[i]]=i;
        }
```
这句判断是为了防止列表中有重复的元素，如果有重复的不存入map。







