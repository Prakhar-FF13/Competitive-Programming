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
int n,k,num;
int T[6];
char ch;
vii g[600];
vi dist, elev[10];
void Dijkstra(){
	dist.assign(600, MOD);
	priority_queue<pii, vii, greater<pii> > pq;
	for(int i = 0 ; i <= 100*n ; i += 100)
		if(g[i].size() > 0){
			pq.push(mp(0,i));
			dist[i] = 0;
		}
	
	while(!pq.empty()){
		pii curr = pq.top(); pq.pop();
		int u = curr.second;
		int w = curr.first;
		if(w > dist[u])
			continue;
		
		for(int i = 0 ; i < (int)g[u].size() ; i++){
			pii v = g[u][i];
		//	cout<<"current cost between "<<u<<" and "<<v.first<<" is "<<dist[v.first]<<"\n";
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(mp(dist[v.first], v.first));
			}
		//	cout<<"updated cost between "<<u<<" and "<<v.first<<" is "<<dist[v.first]<<"\n";
			for(int j = v.first -500 ; j <= 500 ; j += 100 ){
				if(j >= 0 && g[j].size() > 0 && j != v.first){
					if(dist[j] > dist[v.first] + 60){
						dist[j] = dist[v.first] + 60;
						pq.push(mp(dist[j], j));
					}
				}
			}
		}
	}
}
vi visited;
void dfs(int s){
	visited[s] = 1;
	cout<<s<<"\n";
	rep(i,0,(int)g[s].size()){
		if(visited[g[s][i].first] == 0)
			dfs(g[s][i].first);
	}
}
int main(){
	//RW()
	while(cin>>n>>k){
		rep(i,0,n)
			cin>>T[i];
		rep(i,0,10)
			elev[i].clear();
		rep(i,0,n){
			while(scanf("%d%c", &num, &ch)){
				elev[i].pb(num);
				if(ch =='\n')
					break;
			}
		}
		rep(i,0,600)
			g[i].clear();
		rep(i,0,n){
			for(int j = 0 ; j < int(elev[i].size()) - 1 ; j++){
				int a = elev[i][j];
				int b = elev[i][j+1];
				g[i*100 + a].pb(mp(i*100 + b, T[i] * abs(a-b)));
				g[i*100 + b].pb(mp(i*100 + a, T[i] * abs(a-b)));
			}
		}
		Dijkstra();
		int ans = MOD;
		/*for(int i = 0; i < 505 ; i++)
			if(dist[i] != MOD)
				cout<<"floor "<<i<<" cost = "<<dist[i]<<"\n";*/
		for(int i = 0 ; i <= 100 * n ; i += 100 )
			ans = min(ans, dist[k + i]);
		if(ans!=MOD)
			cout<<ans<<"\n";	
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
