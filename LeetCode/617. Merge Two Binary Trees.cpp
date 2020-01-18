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
    TreeNode *merge(TreeNode *t1, TreeNode *t2){
        TreeNode *NodeToReturn; 
        if(t1 == NULL && t2 == NULL)    
            NodeToReturn = NULL;
        
        else if(t1 == NULL && t2 != NULL){
            NodeToReturn = new TreeNode(t2->val);
            NodeToReturn->left = merge(NULL, t2->left);
            NodeToReturn->right = merge(NULL, t2->right);
        }
        
        else if(t1 != NULL && t2 == NULL){
            NodeToReturn = new TreeNode(t1->val);
            NodeToReturn->left = merge(t1->left, NULL);
            NodeToReturn->right = merge(t1->right, NULL);
        }
        
        else{
            NodeToReturn = new TreeNode(t1->val + t2->val);
            NodeToReturn->left = merge(t1->left, t2->left);
            NodeToReturn->right = merge(t1->right, t2->right);
        }
        return NodeToReturn;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode *t2) {
        return merge(t1, t2);
    }
};