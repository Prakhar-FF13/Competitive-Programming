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
    int maxlevel;
    vector<int> ans;
public:
    Solution(){maxlevel=-1;}
    void recurse(TreeNode* root, int level){
        if(!root)   return;
        if(level > maxlevel){maxlevel = level; ans.push_back(root->val);}
        recurse(root->right, level+1);
        recurse(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        recurse(root, 0);
        return ans;
    }
};