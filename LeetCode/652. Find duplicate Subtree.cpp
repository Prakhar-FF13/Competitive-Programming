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
    vector<TreeNode* > ans;
    unordered_map<string, int> m;
public:
    string recurse(TreeNode* root){
        if(root){
            string c,l,r;
            l = recurse(root->left); r = recurse(root->right);
            if(l == "") l += "NULL"; if(r == "") r += "NULL";
            c = to_string(root->val) + l + r;
            m[c]++;
            if(m[c] == 2)   ans.push_back(root);
            return c;
        }
        return "";
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        recurse(root);
        return ans;
    }
};