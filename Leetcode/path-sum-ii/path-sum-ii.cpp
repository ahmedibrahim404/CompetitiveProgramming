class Solution {
private:
  void dfs(TreeNode * root, vector<int> path, int tot, int targetSum, vector<vector<int>>& ans){
    if(root->right == nullptr && root->left == nullptr){
        tot += root->val;
        path.push_back(root->val);
      if(tot == targetSum) ans.push_back(path);
      return;
    }
    
    if(root->right != nullptr){
      vector<int> nPath = path;
      nPath.push_back(root->val);
      dfs(root->right, nPath, tot + root->val, targetSum, ans);
    }
    
    if(root->left != nullptr){
      vector<int> nPath = path;
      nPath.push_back(root->val);
      dfs(root->left, nPath, tot + root->val, targetSum, ans);
    }
        
  } 
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>> ans;
        if(root == nullptr) return ans;
      dfs(root, vector<int>(), 0, targetSum, ans);
      return ans;
    }
};



