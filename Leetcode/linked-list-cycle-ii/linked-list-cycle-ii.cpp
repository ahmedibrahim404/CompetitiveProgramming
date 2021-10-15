
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> st;
        ListNode* cur=head;
        while(cur){
            if(st.count(cur)){
                return cur;
            }
            st.insert(cur);
            cur = cur->next;
        }
        
        return NULL;
        
    }
};