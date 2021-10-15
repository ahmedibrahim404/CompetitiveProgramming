/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;;
        for(int i=0;i<1e4+1;i++){
            if(!head) return false;
            head = head->next;
        }
        
        return true;
        
    }
};