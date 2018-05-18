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

int main()
{
	
	int n,l,u,v,curr;
	bool isitBipartite;
	vi g[10000];
	int color[10000];
	while(cin>>n){
		if(n==0)
			break;
		cin>>l;
		rep(i,0,10000){
			color[i] = -1;
			g[i].clear();
		}
		rep(i,0,l){
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		queue<int> q;
		color[0] = 0;
		q.push(0);
		isitBipartite = true;

		while(!q.empty() && isitBipartite){
			curr = q.front();
			q.pop();
			rep(i,0,(int)g[curr].size()){
				
				if( color[g[curr][i]] == -1 ){
					color[g[curr][i]] = 1 - color[curr];
					q.push(g[curr][i]);
				}
				else if( color[g[curr][i]] == color[curr] ){
					isitBipartite = false;
					break;
				}
			}
		}
		if(isitBipartite)
			cout<<"BICOLORABLE.\n";
		else
			cout<<"NOT BICOLORABLE.\n";
	}
	return 0;
}
