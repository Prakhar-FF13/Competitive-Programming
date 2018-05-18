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
vi taken;
vii g[100000];
priority_queue<pii, vii, greater<pii> > q;
int n,e,u,v,w,mst_cost;
void process(int u){
	taken[u] = 1;
	rep(v,0,(int)g[u].size()){
		pii c = g[u][v];
		if(!taken[c.first]){
			q.push(mp(c.second, c.first));
		}
	}
}
int main()
{
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter total number of edges : ";
	cin>>e;
	cout<<"Enter edges and weights : \n";
	rep(i,0,e){
		cin>>u>>v>>w;
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
	}
	taken.assign(n,0);
	mst_cost = 0;
	process(0);
	while(!q.empty()){
		pii curr = q.top();
		u = curr.second; w = curr.first;
		q.pop();
		if(!taken[u]){
			mst_cost += w;
			process(u);
		}
	}
	cout<<"Minimum Cost of Spanning Tree : ";
	cout<<mst_cost<<"\n";
	return 0;
}
