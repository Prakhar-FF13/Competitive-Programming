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
vi toporder;
vi g[150];
bool visited[150];
int n,m;
void dfs(int u){
	visited[u] = true;
	rep(j,0,(int)g[u].size())
		if(!visited[g[u][j]])
			dfs(g[u][j]);
	
	toporder.pb(u);
}
int main()
{
	//RW()
	int u,v;
	while(cin>>n>>m){
		if(n==0)
			break;
		toporder.clear();
		rep(i,0,150){
			g[i].clear();
			visited[i] = false;
		}
		rep(i,0,m){
			cin>>u>>v;
			g[u].pb(v);
		}
		rep(i,1,n+1)
			if(!visited[i])
				dfs(i);
		for(int k = toporder.size()-1; k>=0; k--){
			cout<<toporder[k];
			if(k!=0)
				cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
