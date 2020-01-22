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
    int ans;
public:
    Solution(){ans = 0;}
    int helper(TreeNode *root){
        if(!root)
            return 0;
        int lVal = helper(root->left);
        int rVal = helper(root->right);
        int newlVal = 0, newrVal = 0;
        if(root->left && root->left->val == root->val)
            newlVal = 1 + lVal;
        if(root->right && root->right->val == root->val)
            newrVal = 1 + rVal;
        
        ans = max(ans, newlVal + newrVal);
        
        return max(newlVal, newrVal);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        ans = max(ans, helper(root));
        return ans;
    }
};