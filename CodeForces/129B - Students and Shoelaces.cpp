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
vector<int> g[110];
int arr[110*110];
int main(){
    int n,m;
    cin>>n>>m;
    ms(arr, 0 , sizeof(arr));
    for(int i = 0 ; i < m ; i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
        arr[u]++;   arr[v]++;
    }
    int ans=0;
    while(1){
        vi ones;
        int cnt=0;
        rep(i, 1, n+1)
            if(arr[i] == 1)
                cnt++, ones.pb(i);
        if(cnt == 0)
            break;
        ans++;
        rep(i, 0, ones.size()){
            int u = ones[i];
            rep(j , 0, g[u].size()){
                int v = g[u][j];
                arr[v]--;
                if(arr[v] < 0) arr[v] = 0;
            }
            g[u].clear();
            arr[u] = 0;
        }
    }
    cout<<ans;
    return 0;
}
