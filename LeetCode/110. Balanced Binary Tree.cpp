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
    bool ans;
public:
    Solution(){
        ans = true;
    }
    int letsGo(TreeNode *root){
        if(!root->left && !root->right)
            return 0;
        
        int rVal = 0, lVal = 0;
        if(root->left)  lVal = letsGo(root->left) + 1;
        if(root->right) rVal = letsGo(root->right) + 1;
        
        if(abs(rVal - lVal) > 1)    ans = false;
        
        return max(lVal, rVal);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)   return ans;
        letsGo(root);
        return ans;
    }
};