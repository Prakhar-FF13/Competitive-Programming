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
vi dfs_num, dfs_low, S, visited;
vii g[10000];
int dfscounter;
int n,e,x,y,w;
void TarjanSSC(int u){
	dfs_num[u] = dfs_low[u] = dfscounter++;
	S.pb(u);
	visited[u] = 1;
	for(int j = 0 ; j < g[u].size() ; j++){
		pii v = g[u][j];
		if(dfs_num[v.first] == -1)
			TarjanSSC(v.first);
		
		if(visited[v.first])
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
	}
	if(dfs_num[u] == dfs_low[u]){
		while(1){
			int x = S.back();
			S.pob();
			visited[x] = 0;
			cout<<x<<" ";
			if(u == x)
				break;
		}
		cout<<"\n";
	}
}
int main()
{
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter total number of edges : ";
	cin>>e;
	rep(i,0,n+5)
		g[i].clear();
	cout<<"Enter the edge with weights : \n";
	rep(i,0,e){
		cin>>x>>y>>w;
		g[x].pb(mp(y,w));
	}
	dfs_num.assign(n,-1); dfs_low.assign(n,-1);
	visited.assign(n,0);
	dfscounter = 0;
	rep(i,0,n)
		if(dfs_num[i] == -1)
			TarjanSSC(i);
	return 0;
}
