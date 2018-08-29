#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int dp[101][101][101], int k){  
  if(k == 0)
    return 0;
  if(s1.length() == 0 || s2.length() == 0)
    return -100000;
  
  if(dp[s1.length()][s2.length()][k] != -1)
    return dp[s1.length()][s2.length()][k];
  
  int ans = 0;
  if(s1[0] == s2[0]){
    int a = LCS(s1.substr(1), s2.substr(1), dp, k);
    int b = LCS(s1.substr(1), s2.substr(1), dp, k-1) + int(s1[0]);
    ans = max(a, b);
  }else{
    int a = LCS(s1.substr(1), s2, dp, k);
    int b = LCS(s1, s2.substr(1), dp, k);
    ans = max(a, b);
  }
  dp[s1.length()][s2.length()][k] = ans;
  return ans;
}

int main()
{
    int t;
    cin>>t;
  	while(t--){
      	string s1, s2;
        cin>>s1>>s2;
        int k; cin>>k;
        int dp[101][101][101];
        for(int i = 0; i  < 101 ; i++)
          for(int j = 0; j < 101 ; j++)
            for(int k = 0 ; k < 101 ; k++)
              dp[i][j][k] = -1;
      
        int ans = LCS(s1, s2, dp, k);
        if(ans < 0)
          ans = 0;
        cout<<ans<<"\n";
        
    }
    return 0;
}
