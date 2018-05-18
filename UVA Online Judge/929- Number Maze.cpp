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
int n,m,w,x,y;
int g[1000][1000];
int dist[1000][1000];
int movex[] = {1,0,-1,0};
int movey[] = {0,1,0,-1};

class Compare{ 
	public:
		bool operator()(pair<int, pii> a, pair<int, pii> b){
			return a.first < b.first;
		}
};
bool valid(int l, int k){
	if(l<n && l>=0 && k<m && k>=0)
		return true;
	return false;
}

void Dijkstra(int u, int v){
	ms(dist, MOD, sizeof(dist));
	dist[u][v] = g[u][v];
	priority_queue<pair<int, pii> , vector<pair<int, pii> >, Compare > pq;
	pq.push(mp(g[u][v], mp(u,v)));
	while(!pq.empty()){
		pair<int, pii> curr = pq.top(); pq.pop();
		x = curr.second.first;
		y = curr.second.second;
		w = curr.first;
		if( w > dist[x][y] )
			continue;
		
		for(int i = 0 ; i < 4 ; i++ ){
			int l = x+movex[i];
			int k = y+movey[i];
			if(valid(l,k)){
				if(dist[x][y] + g[l][k] < dist[l][k]){
					dist[l][k] = dist[x][y] + g[l][k];
					pq.push(mp(dist[l][k],mp(l,k)));
				}
			}
		}
	}
}
int main()
{
	//RW()
	fsi
	tt(){
		cin>>n;
		cin>>m;
		rep(i,0,n)
			rep(j,0,m)
				cin>>g[i][j];
				
		Dijkstra(0,0);
		cout<<dist[n-1][m-1]<<"\n";
	}
	return 0;
}
