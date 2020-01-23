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
    void fillVector(vector<int> &x, int val){
    }
    
    
    void helper2(TreeNode* root, int val, int &cnt){
        if(!root)   return;
        if(root->val == val)    cnt++;
        helper2(root->left, val, cnt);
        helper2(root->right, val, cnt);
    }
    
    void helper(TreeNode* root, vector<int> &x, int &maxCount){
        if(!root)   return;
        int cnt = 0;
        helper2(root, root->val, cnt);
        if(cnt > maxCount){
            x.clear();
            x.push_back(root->val);
            maxCount = cnt;
        }else if(cnt == maxCount){
            x.push_back(root->val);
        }
        helper(root->left, x, maxCount);
        helper(root->right, x, maxCount);
    }
    
    vector<int> findMode(TreeNode* root) {
        if(!root)   return vector<int>();
        vector<int> x;
        int maxCount=0;
        helper(root, x, maxCount);
        return x;
    }
};