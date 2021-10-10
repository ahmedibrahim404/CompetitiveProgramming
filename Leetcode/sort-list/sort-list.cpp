class Solution {
public:
    ListNode* midpoint(ListNode *head){
        if(!head or !head->next){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    } 
    ListNode* merge(ListNode *a,ListNode *b){
        if(!a)
            return b;
        if(!b)
            return a;
        if(a->val<b->val){
            a->next=merge(a->next,b);
            return a;
        }
        else{
            b->next=merge(a,b->next);
            return b;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* mid=midpoint(head);
        ListNode* a=head;
        ListNode* b=mid->next;
        mid->next=NULL;
        a=sortList(a);
        b=sortList(b);
        
        ListNode* c=merge(a,b);
        return c;
    }
};
