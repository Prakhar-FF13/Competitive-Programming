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

int dp[55][55];
int table[55][55];
int main()
{
	string str;
	cin>>str;
	int n = str.length();
	int count = n;
	rep(i,0,n)
		dp[i][i] = table[i][i] = 1;
	
	rep(i,0,n){
		if(i!=n-1 && str[i] == str[i+1]){
			count++;
			dp[i][i+1] = 2;
			table[i][i+1] = 1;
		}
		else if(i+1 != n){
			dp[i][i+1] = 1;
			table[i][i+1] = 0;
		}
	}
	for(int l = 3; l < n + 1; l++){
		rep(i,0,n){
			int j = i + l - 1;			
			if(str[i] == str[j] && table[i+1][j-1] == 1){
				count++;
				dp[i][j] = dp[i+1][j-1] + 2;
				table[i][j] = 1;
			}
			else{
				int c1 = dp[i][j-1];
				int c2 = dp[i+1][j];
				int c3 = dp[i+1][j-1];
				dp[i][j] = max(c1, max(c2, c3));
				table[i][j] = 0;
			}
		}
	}
	cout<<"\n"<<count<<"\n";
	return 0;
}
