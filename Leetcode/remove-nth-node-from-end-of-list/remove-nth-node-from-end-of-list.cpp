class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* cur = head;
        int sz=0;
        while(cur != NULL){
            sz++;
            cur = cur->next;
        }
        
    
        if(sz == 1 && n == 1) return NULL;
        if(n == sz){
            head = head->next;
            return head;
        }

        cur = head;
        sz = sz - n;
        ListNode* par;
        while(sz--){
            if(sz == 0) par = cur;
            cur = cur->next;
        }
        par->next = cur->next;
     
        return head;
    }
};
