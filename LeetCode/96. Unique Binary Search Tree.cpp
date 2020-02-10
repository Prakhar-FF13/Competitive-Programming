class Solution {
    int *dp;
public:
    Solution(){
        dp = new int[20];
        for(int i = 0 ; i < 20 ; i++)
            dp[i] = 0;
        dp[0] = dp[1] = 1;
    }
    int numTrees(int n) {
        if(dp[n])   return dp[n];
        int ans = 0;
        for(int i = 0; i < n ; i++)
            ans += numTrees(i)*numTrees(n-i-1);
        return dp[n] = ans;
    }
};