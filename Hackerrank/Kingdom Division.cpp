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
vi g[(int)1e5+50];
bool visited[(int)1e5+50];
vi child;
vi memo;
int n,u,v;
void DFS(int s){
	visited[s] = true;
	if(g[s].size() == 0){	// Leaf Node ....	
		memo[s] = child[s] = 0;
		return;
	}
	rep(i,0,(int)g[s].size()){
		if(!visited[g[s][i]]){
			child[s]++;
			DFS(g[s][i]);
		}
	}
	memo[s] = 2;
	rep(i,0,(int)g[s].size()){
		if(child[g[s][i]] != 0){
			memo[s] = ((memo[s]%MOD) * (memo[g[s][i]]%MOD))%MOD;
		}
	}
}
int main()
{
	cin>>n;
	rep(i,1,n){
		cin>>u>>v;
		g[u].pb(v);
		//g[v].pb(u);
	}
	ms(visited,false,sizeof(visited));
	memo.assign(n+5, 0);
	child.assign(n+5, 0);
	DFS(1);
	cout<<memo[1]<<"\n";
	return 0;
}
