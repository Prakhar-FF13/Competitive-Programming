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

vi g[1000];
bool visited[1000];
vi topsort;
void TopologicalSort(int vertex){
	visited[vertex] = true;
	for(int i = 0; i < (int)g[vertex].size(); i++)
		if(visited[g[vertex][i]] == false)
			TopologicalSort(g[vertex][i]);
			
	topsort.pb(vertex);
}
int main()
{
	int n; // No of vertices.
	cin>>n;
	int e; // No of edges.
	cin>>e;
	int u,v;
	topsort.clear();
	rep(i,0,e){
		cin>>u>>v; // edge between vertices u and v.
		g[u].pb(v); // TopologicalSort runs on a DAG.
	}
	memset(visited, false, sizeof(visited));
	rep(i,0,n)
		if(visited[i] == false)
			TopologicalSort(i);
			
	for(int i = topsort.size()-1; i>=0 ; i--){
		cout<<topsort[i]<<" ";
	}
	return 0;
}
