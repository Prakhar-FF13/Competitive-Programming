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
vi g[10000];
int n,e,u,v,dfsroot,rootchild;
vi dfs_num(10000), dfs_low(10000), dfs_parent(10000);
vi arti_points(10000);
int dfs_counter;
void dfs(int u){
	dfs_low[u] = dfs_num[u] = dfs_counter++;
	rep(v,0,(int)g[u].size()){
		if(dfs_num[g[u][v]] == -1){
			dfs_parent[g[u][v]] = u;
			if(u == dfsroot)
				rootchild++;
			dfs(g[u][v]);
			
			if(dfs_low[g[u][v]] >= dfs_num[u])
				arti_points[u] = 1;
			if(dfs_low[g[u][v]] > dfs_num[u])
				cout<<"Edge between "<<g[u][v]<<" and "<<u<<" is a bridge\n";
			dfs_low[u] = min(dfs_low[u], dfs_low[g[u][v]]);
		}
		else if(g[u][v] != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u], dfs_num[g[u][v]]);
		}
	}
}
int main()
{
	dfs_counter = 0, dfsroot = 0, rootchild = 0;
	cout<<"\n Enter number of vertices : ";
	cin>>n;
	cout<<"\n Enter number of edges : ";
	cin>>e;
	dfs_num.assign(n,-1); dfs_parent.assign(n,-1); dfs_low.assign(n,-1); arti_points.assign(n,-1);
	cout<<"\n Enter vertices between which an edge exists \n";
	rep(i,0,e){
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i,0,n){
		if(dfs_num[i] == -1){
			dfsroot = i;
			rootchild = 0;
			dfs(i);
			arti_points[i] = rootchild > 1 ? 1 : 0;
		}
	}
	rep(i,0,n){
		if(arti_points[i] == 1)
			cout<<i<<" ";		
	}
	
	return 0;
}
