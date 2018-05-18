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
int n,e,u,v,w;
vii g[10000];
vi dist;
void BellManFord(int s){
	dist.assign(n+5, MOD);
	dist[s] = 0;
	rep(i,0,n-1){ // Important -> Till < n-1 only. 
		rep(u,0,n){
			rep(v,0,(int)g[u].size()){
				pii curr = g[u][v];
				dist[curr.first] = min(dist[curr.first], dist[u] + curr.second);
			}
		}
	}
}
int main()
{
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter number total number of edges : ";
	cin>>e;
	cout<<"Enter edges with weights : \n";
	rep(i,0,e){
		cin>>u>>v>>w;
		g[u].pb(mp(v,w));
	}
	cout<<"Enter the source vertex : ";
	cin>>u;
	BellManFord(u);
	rep(i,0,n)
		if(i!=u)
			cout<<"Shortest Distance of vertex "<<i<<" from source is : "<<dist[i]<<"\n";
			
	return 0;
}
