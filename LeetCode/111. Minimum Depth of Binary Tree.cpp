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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else{
            int t = 1e7;
            if(root->left)
                t = min(t, minDepth(root->left));
            if(root->right)
                t = min(t, minDepth(root->right));
            
            if(t == 1e7)
                return 1;
            else
                return 1 + t;
        }
    }
};