
class Solution {
public:
ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *a=head,*b=head->next,*c=head->next->next;
        a->next=c;
        b->next=a;
        a->next=swapPairs(c);
        return b;
    }
};
