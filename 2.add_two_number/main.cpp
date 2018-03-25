#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
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
void print_list(ListNode *phead){

    while (phead){
        ListNode *tme=phead->next;
        cout<<phead->val;
        phead=tme;
    }
}
ListNode* add_list(ListNode* l1,ListNode* l2){

    ListNode *pnew,*phead;
    int data=0;
    phead=new ListNode(0);
    pnew=phead;
    while (l1 || l2 || data ){
        data= (l1 ? l1->val:0)+(l2 ? l2->val:0)+data;
        pnew->next=new ListNode(data%10);
        pnew=pnew->next;
        (data/10)?data=1:data=0;
        l1=l1?l1->next:l1;
        l2=l2?l2->next:l2;
    }
    return phead->next;
     /*
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
    */
}
int main() {

    ListNode* l1=list_create();
    ListNode* l2=list_create();
    ListNode* l3=add_list(l1,l2);
    print_list(l3);
    return 0;
}