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
int n,m,x,y,r,s;
vi dist;
vii g[3005];
priority_queue<pii, vii, greater<pii> > pq;
void Dijkstra(int s){
	dist.clear();
	dist.assign(n+5,MOD);
	dist[s] = 0;
	pq.push(mp(0,s));
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		int u = curr.second;
		int w = curr.first;
		if( w > dist[u] )
			continue;
		
		for(int i = 0 ; i < (int)g[u].size() ; i++ ){
			pii c = g[u][i];
			if(dist[u] + c.second < dist[c.first]){
				dist[c.first] = dist[u] + c.second;
				pq.push(mp(dist[c.first],c.first));
			}
		}
	}
}
int main()
{
	fsi
	tt(){
		cin>>n>>m;
		rep(i,0,n+2)
			g[i].clear();
		
		rep(i,0,m){
			cin>>x>>y>>r;
			g[x].pb(mp(y,r));
			g[y].pb(mp(x,r));
		}
		cin>>s;
		Dijkstra(s);
		rep(i,1,n+1)
			if(i!=s)
				if(dist[i] == MOD)
					cout<<-1<<" ";
				else
					cout<<dist[i]<<" ";
		cout<<"\n";
	}
}
