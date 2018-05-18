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
int dist[105][105], n ,r, u, v, s, d, ans;
void AllPairShortestPath(){
	rep(k,0,n)
		rep(i,0,n)
			rep(j,0,n)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
}
void Calc(){
	for(int i = 0 ; i < n; i++){
		if(dist[i][d] != MOD && dist[s][i] != MOD)
			ans = max(ans,dist[s][i] + dist[i][d]);
	}
}
int main()
{
	//RW()
	int c = 1;
	tt(){
		cin>>n;
		cin>>r;
		ms(dist,MOD,sizeof(dist));
		rep(i,0,n)
			dist[i][i] = 0;
		rep(i,0,r){
			cin>>u>>v;
			dist[u][v] = dist[v][u] = 1;
		}
		cin>>s>>d;
		ans = 0;
		AllPairShortestPath();
		Calc();
		cout<<"Case "<<c++<<": "<<ans<<"\n";
	}
	return 0;
}
