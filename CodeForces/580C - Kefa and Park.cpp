#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
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
vi graph[int(1e5+5)];
int arr[int(1e5+5)];
bitset<int(1e5+5)> visited;
int ans,n,m;
void dfs(int src, int cnt){
    visited.set(src, 1);
    rep(i, 0, graph[src].size()){
        int neigh = graph[src][i];
        if(visited[neigh] == 0){
            int newCnt = arr[neigh] == 1 ? cnt+1: 0;
            if(newCnt <= m)
                dfs(neigh, newCnt);
        }
    }
    if(graph[src].size() == 1 && src != 0)
        ans++;
}
int main(){
    cin>>n>>m;
    ans = 0;
    rep(i, 0, n)
        cin>>arr[i];
    rep(i, 0, n-1){
        int x,y;
        cin>>x>>y;
        x--, y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    ans = 0 ;
    dfs(0, arr[0] == 1);
    cout<<ans;
    return 0;
}
