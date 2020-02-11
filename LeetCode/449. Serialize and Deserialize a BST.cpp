/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";
        string str = to_string(root->val);
        string l = serialize(root->left), r = serialize(root->right);
        return str + l + r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)  return NULL;
        TreeNode* root = new TreeNode(data[0] - '0');
        string left = "", right = "";
        int i = 1;
        for(; i < data.length() && data[i] < data[0]; i++)
            left += data[i];
        for(; i < data.length() ; i++)
            right += data[i];
        root->left = deserialize(left);
        root->right = deserialize(right);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));