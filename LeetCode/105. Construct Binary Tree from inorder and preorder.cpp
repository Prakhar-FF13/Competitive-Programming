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
    TreeNode* generate(vector<int>& preorder, vector<int>& inorder, int &ind){
        if(inorder.size() == 0) return NULL;
        
        TreeNode* root = new TreeNode(preorder[ind]);
        int i;
        vector<int> left, right;
        for(i = 0 ; i < inorder.size(); i++){
            if(inorder[i] == root->val) break;
            left.push_back(inorder[i]);
        }
        for(i = i+1; i < inorder.size(); i++){
            right.push_back(inorder[i]);
        }
        if(left.size()){ind++;  root->left = generate(preorder, left, ind);  }
        if(right.size()){ind++;  root->right = generate(preorder, right, ind); } 
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return generate(preorder, inorder, ind);
    }
};