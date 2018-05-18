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
#define Explored 2
#define visited 1
#define unvisited 0

int dfs_num[1000];
int dfs_parent[1000];
vi g[1000];
void Graph_check(int vertex){
	dfs_num[vertex] = Explored;
	for(int i = 0; i < g[vertex].size(); i++){
		if(dfs_num[g[vertex][i]] == unvisited){
			dfs_parent[g[vertex][i]] = vertex;
			Graph_check(g[vertex][i]);
		}
		else if(dfs_num[g[vertex][i]] == Explored){
			if(g[vertex][i] == dfs_parent[vertex])
				cout<<" Bidirectional edge between the vertices : "<<vertex<<" and "<<g[vertex][i]<<"\n";
			else
				cout<<" Back Edge (Cycle) between the vertices  : "<<vertex<<" and "<<g[vertex][i]<<"\n";
		}
		else
			cout<<" Forward Edge between the vertices : "<<vertex<<" and "<<g[vertex][i]<<"\n";
	}
	dfs_num[vertex] = visited;
}
int main()
{
	int n;
	cin>>n;
	int e;
	cin>>e;
	rep(i,0,e){
		int u,v;
		cin>>u>>v;
		g[u].pb(v); // Directed Graph;
	}
	int cc = 1;
	rep(i,0,n){
		if(dfs_num[i] == unvisited){
			cout<<" Component : "<<cc++<<" : \n";
			Graph_check(i);
		}
	}
	return 0;
}
