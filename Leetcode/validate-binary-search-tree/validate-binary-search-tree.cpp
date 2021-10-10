class Solution {
public:

    bool isBST(TreeNode* root, long mn=LONG_MIN, long mx=LONG_MAX) {
        
        if(root==NULL)
        {
            return true;
        }
        
        if(root->val>mn && root->val<mx 
           && isBST(root->left,mn,root->val)  // left child can have max value less than parent
           && isBST(root->right,root->val,mx)) //right child can have min vlaue greater than parent
        {
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root)
    {
        return isBST(root);
    }
};