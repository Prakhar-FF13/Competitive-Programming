/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL)
            return vector<int>();
        stack<pair<Node *, int> > s;
        s.push(make_pair(root, 0));
        vector<int> ans;
        while(!s.empty()){
            pair<Node *, int> t = s.top();
            int ind = t.second;
            int childrenCount = t.first->children.size();
            s.pop();
            if(ind == childrenCount){
                ans.push_back(t.first->val);
            }else{
                t.second += 1;
                s.push(t);
                s.push(make_pair(t.first->children[ind], 0));
            }
        }
        return ans;
    }
};