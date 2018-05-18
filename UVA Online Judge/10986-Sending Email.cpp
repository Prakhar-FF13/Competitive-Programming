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
vii g[20005];
priority_queue<pii, vii, greater<pii> > pq;
int n,m,s,t,x,y,d,w;
vi dist;
void Dijkstra(int s){
	dist.assign(n+5, MOD);
	dist[s] = 0;
	pq.push(mp(0,s));
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		int u = curr.second;
		w = curr.first;
		if( w > dist[u] )
			continue;
		for(int i = 0 ; i < (int)g[u].size() ; i++){
			pii v = g[u][i];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(mp(dist[v.first], v.first));
			}
		}
	}
}

int main()
{
	//RW()
	fsi
	int q;
	cin>>q;
	rep(j,0,q){
		cin>>n>>m>>s>>t;
		rep(i,0,n+5)
			g[i].clear();
		
		rep(i,0,m){
			cin>>x>>y>>d;
			g[x].pb(mp(y,d));
			g[y].pb(mp(x,d));
		}
		Dijkstra(s);
		cout<<"Case #"<<j+1<<": ";
		if(dist[t] == MOD)
			cout<<"unreachable";
		else
			cout<<dist[t];
		cout<<"\n";
	}
	return 0;
}
