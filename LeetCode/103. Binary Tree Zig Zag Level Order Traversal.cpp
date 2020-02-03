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
    stack<TreeNode*> s1, s2; bool RtoL;
public:
    Solution(){RtoL = true;}
    void pattern(vector<vector<int>> &x){
        vector<int> q;
        while(s1.size() != 0 || s2.size() != 0){
            q.clear();
            if(RtoL){
                while(s1.size()){
                    TreeNode *t = s1.top();
                    s1.pop();
                    if(t->left) s2.push(t->left); if(t->right) s2.push(t->right);
                    q.push_back(t->val);
                }
            }else{
                while(s2.size()){
                    TreeNode *t = s2.top();
                    s2.pop();
                    if(t->right) s1.push(t->right); if(t->left) s1.push(t->left); 
                    q.push_back(t->val);
                }
            }
            RtoL = !RtoL;
            x.push_back(q);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > x;
        if(!root)   return x;
        s1.push(root);
        pattern(x);
        return x;
    }
};