#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define ii		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define M 	1000000009
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main()
{
	string str,opr;
	cin>>str>>opr;
	int n = str.length();
	ll dp[n + 5][n + 5][2];
	memset(dp, 0, sizeof(dp));
	rep(i,0,n){
		dp[i][i][str[i] - 48] = 1;
	}
	rep(i,0,n-1){
		if ( opr[i] == 'x' ) {
                    dp[i][i+1][0] = (dp[i][i+1][0] + (dp[i][i][1]*dp[i+1][i+1][1])%M)%M;
                    dp[i][i+1][0] = (dp[i][i+1][0] + (dp[i][i][0]*dp[i+1][i+1][0])%M)%M;
                    dp[i][i+1][1] = (dp[i][i+1][1] + (dp[i][i][1]*dp[i+1][i+1][0])%M)%M;
                    dp[i][i+1][1] = (dp[i][i+1][1] + (dp[i][i][0]*dp[i+1][i+1][1])%M)%M;
                }
                else if ( opr[i] == 'o' ) {
                    dp[i][i+1][0] = (dp[i][i+1][0] + (dp[i][i][0]*dp[i+1][i+1][0])%M)%M;
                    dp[i][i+1][1] = (dp[i][i+1][1] + (dp[i][i][0]*dp[i+1][i+1][1])%M)%M;
                    dp[i][i+1][1] = (dp[i][i+1][1] + (dp[i][i][1]*dp[i+1][i+1][0])%M)%M;
                    dp[i][i+1][1] = (dp[i][i+1][1] + (dp[i][i][1]*dp[i+1][i+1][1])%M)%M;
                }
                else if ( opr[i] == 'a' ) {
                    dp[i][i+1][1] = (dp[i][i+1][1] + (dp[i][i][1]*dp[i+1][i+1][1])%M)%M;
                    dp[i][i+1][0] = (dp[i][i+1][0] + (dp[i][i][1]*dp[i+1][i+1][0])%M)%M;
                    dp[i][i+1][0] = (dp[i][i+1][0] + (dp[i][i][0]*dp[i+1][i+1][1])%M)%M;
                    dp[i][i+1][0] = (dp[i][i+1][0] + (dp[i][i][0]*dp[i+1][i+1][0])%M)%M;
				}
	}
	int j;
	rep(l,3,n+1){
		rep(i,0,n-l+1){
			j = i + l - 1;
			if(i>=j-1 || j >= n)
				break;
			dp[i][j][0] = dp[i][j][1] = 0;
			rep(k,i,j){
					if ( opr[k] == 'x' ) {
                    dp[i][j][0] = (dp[i][j][0] + (dp[i][k][1]*dp[k+1][j][1])%M)%M;
                    dp[i][j][0] = (dp[i][j][0] + (dp[i][k][0]*dp[k+1][j][0])%M)%M;
                    dp[i][j][1] = (dp[i][j][1] + (dp[i][k][1]*dp[k+1][j][0])%M)%M;
                    dp[i][j][1] = (dp[i][j][1] + (dp[i][k][0]*dp[k+1][j][1])%M)%M;
                }
                else if ( opr[k] == 'o' ) {
                    dp[i][j][0] = (dp[i][j][0] + (dp[i][k][0]*dp[k+1][j][0])%M)%M;
                    dp[i][j][1] = (dp[i][j][1] + (dp[i][k][0]*dp[k+1][j][1])%M)%M;
                    dp[i][j][1] = (dp[i][j][1] + (dp[i][k][1]*dp[k+1][j][0])%M)%M;
                    dp[i][j][1] = (dp[i][j][1] + (dp[i][k][1]*dp[k+1][j][1])%M)%M;
                }
                else if ( opr[k] == 'a' ) {
                    dp[i][j][1] = (dp[i][j][1] + (dp[i][k][1]*dp[k+1][j][1])%M)%M;
                    dp[i][j][0] = (dp[i][j][0] + (dp[i][k][1]*dp[k+1][j][0])%M)%M;
                    dp[i][j][0] = (dp[i][j][0] + (dp[i][k][0]*dp[k+1][j][1])%M)%M;
                    dp[i][j][0] = (dp[i][j][0] + (dp[i][k][0]*dp[k+1][j][0])%M)%M;
				}
			}
		}
	}
	ll q,x,y;
	string res;
	cin>>q;
/*	rep(i,0,n){
		rep(j,0,n)
			cout<<dp[i][j][1]<<" ";
			
		cout<<"\n";
	}*/
	while(q--){
		cin>>x>>y>>res;
		if(res == "true")
			cout<<dp[x-1][y-1][1]<<"\n";
		else
			cout<<dp[x-1][y-1][0]<<"\n";
	}
	return 0;
}
