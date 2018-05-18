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
int arr[105][105];
int dp[105][105];
int main()
{
	int n;
	cin>>n;
	rep(i,0,n)
		rep(j,0,n){
			dp[i][j] = 0;
			cin>>arr[i][j];
		}
	
	rep(i,0,n){
		rep(j,0,n){
			dp[i][j] = arr[i][j];
			if(i > 0)	dp[i][j] += dp[i-1][j];
			if(j > 0)	dp[i][j] += dp[i][j-1];
			if(i > 0 && j > 0)	dp[i][j] -= dp[i-1][j-1];
		}
	}

	int maxsubRect = (int)(-1e9);
	rep(i,0,n){
		rep(j,0,n){
			rep(l,i,n){
				rep(m,j,n){
					int sum = 0;
					sum += dp[l][m];
					if( i > 0 ) sum -= dp[i-1][m];
					if( j > 0 ) sum -= dp[l][j-1];
					if( i > 0 && j > 0 ) sum += dp[i-1][j-1];
					maxsubRect = max(maxsubRect, sum);
				}
			}
		}
	}
	cout<<maxsubRect<<"\n";
	return 0;
}
