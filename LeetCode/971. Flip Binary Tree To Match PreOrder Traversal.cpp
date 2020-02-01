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
    vector<int> notPos;
    Solution(){
        notPos.push_back(-1);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int ind = 0;
        return flipMatchVoyage(root, voyage, ind);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage, int &ind) {
        if(!root)   return vector<int>();
        if(root->val != voyage[ind])    return notPos;
        bool change = false;
        if(root->left && root->left->val != voyage[ind+1]){
            TreeNode* t = root->left;   change = true;
            root->left = root->right;   root->right = t;    
        }
        vector<int> x,y;
        ind++; // left child has index+1, but right child does not have index+2
        // to get index of right child we first traverse all of left part increase ind
        x = flipMatchVoyage(root->left, voyage, ind);
        y = flipMatchVoyage(root->right, voyage, ind);
        
        if(x.size() && x[x.size()-1] == -1)
            return notPos;
        if(y.size() && y[y.size()-1] == -1)
            return notPos;
        if(change)  x.push_back(root->val);
        x.insert(x.end(), y.begin(), y.end());
        return x;
    }
};