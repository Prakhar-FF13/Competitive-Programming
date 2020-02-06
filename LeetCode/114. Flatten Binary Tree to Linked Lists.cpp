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
    TreeNode* flatten2(TreeNode* root){
        if(!root)   return NULL;
        if(!root->left && !root->right){root->left = root; return root;}
        
        TreeNode* l = flatten2(root->left);
        TreeNode* r = flatten2(root->right);
        
        if(l){
            root->right = l;
            l->left->right = r;
            if(r)   root->left = r->left;
            else    root->left = l->left;
        }else if(r){
            root->right = r;
            root->left = r->left;
        }
        // we longer need left part end and right part end as we have already merged the list.
        if(l)   l->left = NULL;
        if(r)   r->left = NULL;
        return root;
    }
    void flatten(TreeNode* root) {
        root = flatten2(root);
        if(root)    root->left = NULL; // no longer need list's end.
    }
};