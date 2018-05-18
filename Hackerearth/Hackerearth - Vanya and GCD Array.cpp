#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
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

ll dp[1005][1005];
int main()
{
	rep(i,0,1002){
		dp[0][i] = 0;
		dp[i][0] = 1;
	}
	rep(i,1,1002)
		rep(j,1,1002)
			dp[i][j] = (dp[i-1][j-1]%MOD + dp[i-1][j]%MOD) % MOD;
	int t,n,p;
	ll sum;
	scanf("%d",&t);
	t++;
	while(--t){
		sum = 0;
		scanf("%d%d",&n,&p);
		rep(i,0,p+1){
			sum += dp[n][i];
		}
		printf("%lli\n",sum%MOD);
	}
	return 0;
}
