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

int main(){
	//RW()
	int v,a,b;
	vi g[350];
	int color[350];
	while(cin>>v, v!=0){
		rep(i,0,350){
			g[i].clear();
			color[i] = -1;
		}
		while(cin>>a>>b, a!=0 && b!=0){
			g[a].pb(b);
			g[b].pb(a);
		}
		queue<int> q;
		color[1] = 0;
		q.push(1);
		int x;
		bool Bipartite = true;
		while(!q.empty() && Bipartite){
			x = q.front();
			q.pop();
			for(int j = 0; j<(int)g[x].size() ; j++){
				if( color[g[x][j]] == -1 ){
					color[g[x][j]] = 1 - color[x];
					q.push(g[x][j]);
				}
				else if( color[g[x][j]] == color[x] ){
					Bipartite = false;
					break;
				}
			}
		}
		if(Bipartite)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
