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
int n, x, y, articount, dfscounter, dfsroot, rootchild;
char c;
vi g[150];
vi dfs_num(150), dfs_low(150), dfs_parent(150);
vi arti(150);
void network(int u){
	dfs_low[u] = dfs_num[u] = dfscounter++;
	for( int v = 0 ; v < (int)(g[u].size()) ; v++ ){
		if( dfs_num[g[u][v]] == -1 ){
			if( u == dfsroot )
				rootchild++;
			dfs_parent[g[u][v]] = u;
			network(g[u][v]);
			
			if( dfs_low[g[u][v]] >= dfs_num[u] )
				arti[u] = 1;
			
			dfs_low[u] = min( dfs_low[u], dfs_low[g[u][v]] );
		}
		else if( g[u][v] != dfs_parent[u] )
			dfs_low[u] = min( dfs_low[u], dfs_num[g[u][v]] );
	}
}
int main()
{
	//RW()
	while(cin>>n, n!=0){
		rep(i,0,150)
			g[i].clear();
		while(cin>>x, x!=0){
			while(scanf("%d%c", &y, &c) == 2){
				g[x].pb(y);
				g[y].pb(x);
				if(c=='\n')
					break;
			}
		}
		dfs_num.assign(150, -1); dfs_low.assign(150, -1); dfs_parent.assign(150, -1); arti.assign(150, -1);
		articount = dfscounter = 0;
			
		rep(i,1,n+1){
			if(dfs_num[i] == -1){
				rootchild = 0;
				dfsroot = i;
				network(i);
				arti[i] = (rootchild > 1) ? 1 : 0;
			}
		}
		rep(i,1,n+1)
			if(arti[i] == 1)
				articount++;
	
		cout<<articount<<"\n";
	}
	
	return 0;
}
