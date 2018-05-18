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
int n, e, u, v, w, s;
vi dist;
vii g[10000];
priority_queue<pii, vii, greater<pii> > pq;

void Dijkstra(int s){
	dist.assign(n+3, MOD);
	dist[s] = 0;
	pq.push(mp(0,s));
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		w = curr.first;
		u = curr.second;
		if( w > dist[u] )
			continue;
		
		for(v = 0; v < g[u].size(); v++){
			pii c = g[u][v];
			if( dist[u] + c.second < dist[c.first] ){
				dist[c.first] = dist[u] + c.second; 
				pq.push(mp(dist[c.first], c.first));
			}
		}
	}
}
int main()
{
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter total number of edges : ";
	cin>>e;
	cout<<"Enter the edges along with weights : \n";
	rep(i,0,e){
		cin>>u>>v>>w;
		g[u].push_back(mp(v,w));
	}
	cout<<"Enter source vertex : ";
	cin>>s;
	cout<<"Shortest Distance between any other vertex from source vertex is : \n";
	Dijkstra(s);
	rep(i,0,n){
		if(i!=s)
			cout<<"Vertex "<<i<<" is a distance of : "<<dist[i]<<" from source.\n";
	}
	return 0;
}
