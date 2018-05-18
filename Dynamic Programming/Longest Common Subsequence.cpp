#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;

vc LCS(string s1,string s2){
	int n = s1.length();		
	int m = s2.length();
	int dp[n+1][m+1];						// matrix which will store the current max subsequence obtained. 
	int pos[n+1][m+1];						// Anything from this point onwards is hard to explain :D
	memset(dp,-1,sizeof(dp));
	memset(pos,-1,sizeof(pos));
	vc LCSstr;
	
	// Main Loops for LCS calculation.
	
	for(int i = 0; i <= n; i++){
		
		for(int j = 0; j <= m; j++){
			if( i==0 || j==0 ){
				dp[i][j] = 0;
			}
			else if( s1[i-1] == s2[j-1] ){
				dp[i][j] = dp[i-1][j-1] + 1;
				pos[i][j] = 0; 
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(dp[i-1][j] >= dp[i][j-1])
					pos[i][j] = 2;
				else if(dp[i][j-1] >= dp[i-1][j])
					pos[i][j] = 1;
			}
		}
	}
	
	// We have calculate the LCS now to store it we use the pos matrix.
	
	while(m>=1 && n>=1){
		if(pos[n][m] == 0){
			LCSstr.push_back(s1[n-1]);
			n--;
			m--;
		}
		else if(pos[n][m] == 2)
			n--;
		else if(pos[n][m] == 1)
			m--;
	}
	
	// The LCS calculated is in reversed order so while printing start from the end. (See main Fucntion)
	return LCSstr;
}

int main()
{
	vc lcs;
	string s1,s2;
	cout<<"\n Enter string 1 : ";
	cin>>s1;
	cout<<" Enter string 2 : ";
	cin>>s2;
	lcs = LCS(s1,s2);
	cout<<" Longest Common Subsequence for the given strings is : ";
	for(vc::reverse_iterator i = lcs.rbegin(); i < lcs.rend(); i++)
		cout<<*i;
		
	return 0;
}
