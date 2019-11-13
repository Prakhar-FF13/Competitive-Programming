#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main(){
    RW()
    tt(){
        string str;
        cin>>str;
        int n = str.length();
        vector<vector<ll> > dp(n+1, vector<ll>(n+1, 1)); // stores subsequences from i to j.
        // base case of length 2 palindromes
        for(int i = 0; i < n-1 ; i++)
            dp[i][i+1] = (str[i] == str[i+1]) ? 3 : 2; // if s[i] == s[i+1], then 3 subsequences of palindrome are - s[i], s[i+1], s[i] s[i+1] together. else only two s[i], s[i+1].

        for(int k = 2; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                int j = i+k;
                if(j > n) break;
                // Case 1: when s[i] == s[j] 3 ways to form palindromes from i to j.
                // 1. palindromes from [i+1...j-1]. all these are included in 2 and 3 so we need to subtract these.
                // 2. palindromes from [i...j-1].
                // 3. palindromes from [i+1....j].
                // 4. palindromes having i as start and j as end, this is new palindromes and equal -> 1 + [i+1...j-1]

                if(str[i] == str[j]){
                    // [i+1...j] + [i...j-1] - [i+1...j-1] (double counting) + (1 + dp[i+1][j-1])(new palindrome)
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + 1 + dp[i+1][j-1];
                }else{
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }

            }
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}
