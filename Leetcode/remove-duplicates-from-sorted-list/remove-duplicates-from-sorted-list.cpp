


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        
        ListNode* traverse = head->next, *ans = head;
        int pre=ans->val;
        while(traverse){
            if(traverse->val != pre){
                ans->next = traverse;
                ans = ans->next;
                pre = ans->val;
            }
            traverse = traverse->next;
        }
        
        ans->next=NULL;
        
        return head;
        
    }
};

