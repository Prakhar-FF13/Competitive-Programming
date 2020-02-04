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
    string ans; Solution(){ans = "";}
    void getMin(TreeNode* root, string str){
        if(!root->left && !root->right){
            str += char(root->val + 'a');
            reverse(str.begin(), str.end());
            if(ans == "")   ans = str;
            else            ans = min(ans, str);
            
            return;
        }
        if(root->left)  getMin(root->left, str + char(root->val + 'a'));
        if(root->right) getMin(root->right, str + char(root->val + 'a'));
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root)   return "";
        getMin(root, "");
        return ans;
    }
};