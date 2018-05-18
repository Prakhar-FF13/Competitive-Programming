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
vi dfs_num, dfs_low, visited, S, g[10000];
int dfscounter, n, e, x, y, numSSC;

void tarjanSSC(int u){
	dfs_low[u] = dfs_num[u] = dfscounter++;
	S.pb(u);
	visited[u] = 1;
	rep(v,0,(int)g[u].size()){
		if(dfs_num[g[u][v]] == -1)
			tarjanSSC(g[u][v]);
		if(visited[g[u][v]])
			dfs_low[u] = min(dfs_low[u], dfs_low[g[u][v]]);
	}
	if(dfs_low[u] == dfs_num[u]){
		cout<<"SSC "<<numSSC++<<" : ";
		while(1){
			int v = S.back(); S.pob(); visited[v] = 0;
			cout<<v<<" ";
			if(u == v)
				break;
		}
		cout<<"\n";
	}
}

int main()
{
	cout<<"Enter the number of vertices : ";
	cin>>n;
	dfs_num.assign(n, -1); dfs_low.assign(n, -1); visited.assign(n, -1);
	dfscounter = numSSC = 0;
	cout<<"Enter number of edgres : ";
	cin>>e;
	cout<<"Enter edges :\n";
	rep(i,0,e){
		cin>>x>>y;
		g[x].pb(y);
	}
	rep(i,0,n){
		if(dfs_num[i] == -1)
			tarjanSSC(i);
	}
	return 0;
}
