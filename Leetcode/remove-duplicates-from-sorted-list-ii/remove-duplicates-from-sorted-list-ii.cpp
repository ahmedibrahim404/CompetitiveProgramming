/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    
        ListNode* cur = head;
        ListNode* ans = new ListNode();
        ListNode* trav = ans;
        while(cur){
            
            cur = cur;
            int val = cur->val, sz=0;
            while(true){
                sz++;
                cur = cur->next;
                if(!cur) break;
                if(cur->val != val) break;
            }
            
            if(sz == 1) {
                trav->next = new ListNode(val);
                trav = trav->next;
            }
            
            
        }
        
        return ans->next;
        
    }
};