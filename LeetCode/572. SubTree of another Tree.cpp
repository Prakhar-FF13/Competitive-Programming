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
    bool checkSubTree(TreeNode* s, TreeNode* t){
        if(!s && !t)    return true;
        if(!s && t)     return false;
        if(s && !t)     return false;
        
        if(s->val == t->val){
            return checkSubTree(s->left, t->left) && checkSubTree(s->right, t->right); 
        }else{
            return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)    return true;
        if(!s && t)     return false;
        if(s && !t)     return false;
        
        if(s->val == t->val && checkSubTree(s, t))  return true;
        
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};