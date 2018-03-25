# add_two-number

> 题目描述：给定两个**非空**链表来代表两个非负数，位数按照**逆序**方式存储，它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
>
> 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
>
> **示例：**
>
> ```
> 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
> 输出：7 -> 0 -> 8
> 原因：342 + 465 = 807
> ```

Listnode数据结构

~~~
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
~~~

创建单项链表

~~~
ListNode* list_create(){
    ListNode*   phead,*pcurrent,*pnew;
    int data;
    phead = new ListNode(0);
    pcurrent = phead;
    cin>>data;
    while (data!=-1){
        pnew=new ListNode(data);
        pcurrent->next=pnew;
        pcurrent=pnew;
        cin>>data;
    }
    return phead->next;
}
~~~

输出单项链表

~~~
void print_list(ListNode *phead){

    while (phead){
        ListNode *tme=phead->next;
        cout<<phead->val;
        phead=tme;
    }
}
~~~

<表达式1>?<表达式2>:<表达式3>;

如果表达式1成立执行表达式2不成立执行表达式3.



