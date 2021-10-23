class Solution {
private:
    ListNode* findMidNode(ListNode* left, ListNode* right) {
        ListNode *slow, *fast;
        slow = fast = left;
        while (fast != right) {
            fast = fast->next;
            if (fast != right) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    TreeNode* makeTree(ListNode* left, ListNode* right) {
        if (left == right) return NULL;
        ListNode* mid = findMidNode(left, right);
        TreeNode* node = new TreeNode(mid->val, NULL, NULL);
        node->left = makeTree(left, mid);
        node->right = makeTree(mid->next, right);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return makeTree(head, NULL);
    }
};