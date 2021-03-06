/*
    HAsh table prefix sum
    Very good problem
*/

class Solution {
public:
    int beautySum(string s) {
        int len = s.length();
        int ans = 0;
        int prefix[len][26];
        
        for(int i = 0 ;i < len ; i++)
            for(int j = 0; j < 26 ; j++)
                prefix[i][j] = 0;

        for(int i = 0 ; i < len ; i++)
            prefix[i][s[i] - 'a'] = 1;

        for(int i = 1; i < len ; i++)
            for(int j = 0 ; j < 26; j++)
                prefix[i][j] += prefix[i-1][j];
            
        
        for(int i = 0; i < len; i++) {
            for(int j = i; j < len; j++) {
                int largest = -1e9, smallest = 1e9;
                // cout<<i<<" "<<j<<"   -   "<<endl;
                for(int k = 0 ; k < 26; k++) {
                    int countI = prefix[j][k] - (i-1 >= 0 ? prefix[i-1][k]: 0);
                    if (countI == 0)    continue;
                    if (countI > largest)   largest = countI;
                    if (countI < smallest)  smallest = countI;
                }
                // cout<<largest<<" "<<smallest<<endl;
                ans += largest - smallest;
            }
        }       
        return ans;
    }
};