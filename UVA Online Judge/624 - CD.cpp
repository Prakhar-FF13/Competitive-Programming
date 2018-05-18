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

void solve(int n, int t, int index, vi &ans, vi curr, int &sum,int currsum, vi track){
	if(index == t){
		if(currsum <= n && currsum > sum){
			ans = curr;
			sum = currsum;
		}
	}
	else
	{
		curr[index] = 1;
		solve(n, t, index+1, ans, curr, sum, currsum + track[index], track);
		curr[index] = 0;
		solve(n, t, index+1, ans, curr, sum, currsum, track);
	}
}
int main()
{
	
	int n,t;
	while(cin>>n>>t){
		vi arr(t);
		rep(i,0,t)
			cin>>arr[i];
		int sum = 0;
		vi ans(t);
		vi curr(t);
		rep(i,0,t){
			curr[i]=0;
			ans[i]=0;
		}
		solve(n, t, 0, ans, curr, sum, 0, arr);
		rep(i,0,t){
			if(ans[i])
				cout<<arr[i]<<" "; 
		}
		cout<<"sum:"<<sum<<"\n";
	}
}
