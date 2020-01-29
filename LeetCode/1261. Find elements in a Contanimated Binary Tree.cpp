/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_map<int, int> m;
    FindElements(TreeNode* root) {
        if(root->val == -1)
            root->val = 0;
        
        m.clear();
        reconstruct(root, 0);
    }
    
    void reconstruct(TreeNode* root, int val){
        if(!root)   return;
        if(root->val == -1)
            root->val = val, m[val]++;
        reconstruct(root->left, (val<<1) +  1);
        reconstruct(root->right, (val<<1) + 2);
    }
    
    bool find(int target) {
        return m[target] > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */