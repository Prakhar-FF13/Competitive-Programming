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
    unordered_map<int, vector<TreeNode* > > trees;
    Solution(){
        trees.clear();
        trees[1].push_back(new TreeNode(0));
    }
    vector<TreeNode*> allPoss(int N){
        if(N == 0 || N % 2 == 0)
            return vector<TreeNode*>();
        if(trees[N].size() > 0)
            return trees[N];
        vector<TreeNode* > left, right, thisTree;
        for(int i = 1; i <= N-1 ; i++){
            if(trees[i].size() == 0)    left = allPoss(i);
            else                        left = trees[i];
            if(trees[N-1-i].size() == 0)                        right = allPoss(N-1-i);
            else                                                right = trees[N-1-i];
            
            
            for(int l = 0 ; l < left.size(); l++){
                for(int r = 0 ; r < right.size(); r++){
                    TreeNode* root = new TreeNode(0);
                    root->left = left[l]; root->right = right[r];
                    thisTree.push_back(root);
                }
            }
        }
        trees[N] = thisTree;
        return thisTree;
    }
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0)  return vector<TreeNode*>();
        return allPoss(N);
    }
};