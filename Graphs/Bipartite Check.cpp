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

int main()
{
	int n;
	cin>>n; // no of vertices.
	int e;
	cin>>e; // no of edges.
	vi g[n]; // Adjacency list representation of graph.
	rep(i,0,e){
		int u,v;
		cin>>u>>v; // Edge between u and v.
		g[u].pb(v);
	}
	int color[n];
	memset(color, -1, sizeof(color));
	queue<int> q;
	q.push(0); // Start vertex.
	color[0] = 0;
	bool isBipartite = true;
	while(!q.empty() && isBipartite){
		int x = q.front();
		q.pop();
		for(int i = 0; i < g[x].size(); i++){
			if(color[g[x][i]] == -1){
				color[g[x][i]] = 1 - color[x];
				q.push(g[x][i]);
			}
			else if(color[g[x][i]] == color[x]){
				isBipartite = false;
				break;
			}
		}
	}
	if(isBipartite)
		cout<<"Given graph is a Bipartite Graph\n";
	else
		cout<<"Given graph is not a Bipartite Graph\n";
	return 0;
}
