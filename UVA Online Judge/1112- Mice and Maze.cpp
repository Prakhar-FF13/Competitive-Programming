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
vii g[150];
vi dist;
priority_queue<pii, vii, greater<pii> > pq;
int n,m,e,q,a,b,d,w,u,cnt;
void Dijkstra(int s){
	dist.clear();
	dist.assign(n+3, MOD);
	dist[s] = 0;
	pq.push(mp(0, s));
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		u = curr.second;
		w = curr.first;
		if( w > dist[u] )
			continue;
		
		for( int i = 0 ; i < (int)g[u].size() ; i++ ){
			pii v = g[u][i];
			if( dist[u] + v.second < dist[v.first] ){
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
	tt(){
		cin>>n>>e>>q>>m;
		rep(i,0,150)
			g[i].clear();
		rep(i,0,m){
			cin>>a>>b>>d;
			g[b].pb(mp(a,d));
		}
		cnt = 0;
		Dijkstra(e);
		rep(i,1,(int)dist.size())
			if( dist[i] <= q )
				cnt++;
		cout<<cnt<<"\n";
		if(t)
			cout<<"\n";
	}
	return 0;
}
