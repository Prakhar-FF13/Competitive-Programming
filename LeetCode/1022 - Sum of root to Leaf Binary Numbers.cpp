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
    void sumHelper(TreeNode* root, int value){
        if(!root)
            return;
        if(!root->left && !root->right){
            ans += (value<<1) | (root->val);
            return;
        }
        int nv = ((value<<1) | (root->val));
        sumHelper(root->left, nv);
        sumHelper(root->right, nv);
    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        sumHelper(root, 0);
        return ans;
    }
};