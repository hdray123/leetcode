# 31.Next Permutation

实现获取下一个排列函数，这个算法需要将数字重新排列成字典序中数字更大的排列。

如果不存在更大的排列，则重新将数字排列成最小的排列（即升序排列）。

修改必须是原地的，不开辟额外的内存空间。

这是一些例子，输入位于左侧列，其相应输出位于右侧列。
`1,2,3` → `1,3,2`
`3,2,1` → `1,2,3`
`1,1,5` → `1,5,1`

代码：

```c++
void swap(vector<int>& nums,int i,int e){
	int temp;
    temp=nums[i];
    nums[i]=nums[e];
    nums[e]=temp;
}
void reverse(vector<int>& nums,int s,int e){
    while(s<e){
        swap(nums,s,e);
        s++;
        e--;
    }
}
void nextPermutation(vector<int>& nums) {
    int n=nums.size()-1,p=-1;
    for(int i=n-1;i>-1;i--){
        if(nums[i]<nums[i+1]){
            p=i;
            break;
        }
    }
    if(p==-1){
        reverse(nums,0,n);
        return;
    }
    for(int i=n;i>-1;i--){
        if(nums[i]>nums[p]){
            swap(nums,i,p);
            break;
        }
    }
    reverse(nums,p+1,n);
    
}
```
想法：

1->2->3->6->5->4

先判断从尾部到首部是否为升序，如果是就倒置，如果不是则保留那个不是升序的下标与升序队列中比他大的交换。这样3和4交换可以明显看出123xxx小于124xxx,然后124xxx又要尽量贴近123xxx 随意将本来升序的XXX队列转换成倒序的reverse(XXX)队列。所以`1->2->4->3->5->6`是`1->2->3->6->5->4`的下一个队列

。

