class Solution {
public:
    
    int mostSigniFicantBit(int lbl){
        int cnt = 0;
        while(lbl){
            lbl = lbl>>1;
            cnt++;
        }
        return cnt;
    }
    
    void findPath(int label, vector<int> &ans){
        int height = mostSigniFicantBit(label);
        height--;
        while(label != 1){
            ans.push_back(label);
            int x = label/2;
            int lastNumb = (1<<(height)) - 1; // last number in previous level.
            int firstNumb = 1<<(height-1); // first num in previous level.
            
            // calculate label
            label = firstNumb + lastNumb - x;
            height--;
        }
        ans.push_back(1);
    }
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        findPath(label, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};