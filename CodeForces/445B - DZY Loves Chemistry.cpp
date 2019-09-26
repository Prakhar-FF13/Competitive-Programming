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
int n,m;
vector<int> g[100];
int visited[100];

void dfs(int src){
    visited[src] = 1;
    rep(i, 0, g[src].size()){
        if(!visited[g[src][i]])
            dfs(g[src][i]);
    }
}

int main(){
    cin>>n>>m;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int conn_comp_count=0;
    ms(visited, 0, sizeof(visited));
    rep(i,1,n+1){
        if(!visited[i]){
            conn_comp_count++;
            dfs(i);
        }
    }
    cout<<pow(2, n-conn_comp_count);
    return 0;
}
