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
int n, x, y, curr, dlinks, dfscounter;
char c1,c2;
#define MAX 10000
vi g[MAX];
vi dfs_num(MAX), dfs_low(MAX), dfs_parent(MAX);
vii bridge;
void critical_links(int u){
	dfs_low[u] = dfs_num[u] = dfscounter++;
	for( int v = 0 ; v < (int)(g[u].size()) ; v++ ){
		if( dfs_num[g[u][v]] == -1 ){
			dfs_parent[g[u][v]] = u;
			critical_links(g[u][v]);
			
			if( dfs_low[g[u][v]] > dfs_num[u] )
				bridge.pb(mp( min(g[u][v],u) , max(g[u][v], u)));
			
			dfs_low[u] = min( dfs_low[u], dfs_low[g[u][v]] );
		}
		else if( g[u][v] != dfs_parent[u] )
			dfs_low[u] = min( dfs_low[u], dfs_num[g[u][v]] );
	}
}
bool Compare(pii a, pii b){
	if(a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}
int main()
{
	//RW()
	while(cin>>n){
		if(n == 0){
			cout<<"0 critical links\n\n";
			continue;
		}
		dfs_num.assign(MAX, -1); dfs_low.assign(MAX, -1); dfs_parent.assign(MAX, -1); 
		bridge.clear();
		rep(i,0,MAX)
			g[i].clear();
		
		rep(i,0,n){
			cin>>curr>>c1>>dlinks>>c2;
			rep(j,0,dlinks){
				cin>>x;
				g[curr].pb(x);
				g[x].pb(curr);
			}
		}
		rep(i,0,n){
			if(dfs_num[i] == -1){
				critical_links(i);
			}
		}
		sort(bridge.begin(), bridge.end(), Compare);
		cout<<bridge.size()<<" critical links\n";
		rep(i,0,bridge.size())
			cout<<bridge[i].first<<" - "<<bridge[i].second<<"\n";
		
		cout<<"\n";
	}
	return 0;
}
