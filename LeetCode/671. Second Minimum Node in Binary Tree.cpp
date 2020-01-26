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
    
    long long func(TreeNode* root, long long minimum){
        if(!root)   return 1e15*1LL;
        
        if(root->val != minimum)    return root->val * 1LL;
        
        return min( func(root->left, minimum) *1LL, func(root->right, minimum)*1LL );
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        long long ans = func(root, root->val);
        if(ans == 1e15) ans = -1;
        return ans;
    }
};