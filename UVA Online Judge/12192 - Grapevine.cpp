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


int arr[600][600];

int main()
{
	//RW()
	int n,m;
	while(cin>>n>>m){
		if(n == 0 && m == 0)
			break;

		rep(i,0,n)
			rep(j,0,m)
				cin>>arr[i][j];
				
		int q;
		cin>>q;
		while(q--)
		{
			int l,u;
			cin>>l>>u;
			int ans = 0;
			rep(i,0,n){
				int *s = lower_bound(arr[i], arr[i]+m, l); 	
				int curr = s - arr[i];
				if(curr!=-1){
					int j = curr;
					int q = i;
					while(arr[q][j] <= u && q<n && j<m)
						q++,j++;	
					q--,j--;	
					ans = max(q-i+1,ans);
				} 
			}
			cout<<ans<<"\n";
		}
		cout<<"-\n";
	}
	return 0;
}
