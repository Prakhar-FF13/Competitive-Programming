/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool pathSum(TreeNode* root, int sum){
        if(!root)
            return false;
        //cout<<root->val<<" "<<sum<<endl;
        if(!root->left && !root->right && sum == root->val)
            return true;
        return pathSum(root->left, sum - root->val) || pathSum(root->right, sum - root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        return pathSum(root, sum);
    }
};