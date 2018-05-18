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

int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	ll  dp[n+2][n+2];
	rep(i,0,n)
		rep(j,0,n){
		cin>>arr[i][j];
		dp[i][j] = 1;
	}
	rep(i,0,n){
		rep(j,0,n){
			if( i > 0 && arr[i][j] > arr[i-1][j] )
				dp[i][j] = (dp[i][j]%MOD + (dp[i][j]%MOD * dp[i-1][j]%MOD)%MOD)%MOD;
			if( j > 0 && arr[i][j] > arr[i][j-1] )
				dp[i][j] = (dp[i][j]%MOD + (dp[i][j]%MOD * dp[i][j-1]%MOD)%MOD)%MOD;
				
			if( i > 0 )
				dp[i][j] = (dp[i][j]%MOD + dp[i-1][j]%MOD)%MOD;
			if( j > 0 )
				dp[i][j] = (dp[i][j]%MOD + dp[i][j-1]%MOD)%MOD;
		}
	}
	rep(i,0,n){
		rep(j,0,n)
			cout<<dp[i][j]<<" ";
			
		cout<<"\n";
	}
	cout<<dp[n-1][n-1]<<"\n";
	return 0;
}
