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
int visited[20105];
int dist[20105];
queue<int> numb;
int solve(){
    if(n == m)
        return 0;
    numb.push(n);
    dist[n] = 0;
    while ( !numb.empty() ) {
        int x = numb.front();
        numb.pop();
        if(visited[x] == 1) continue;
        visited[x] = 1;
        if(x - 1 > 0 && visited[x-1] == 0){
            numb.push(x-1);
            dist[x-1] = dist[x] + 1;
        }
        if(2*x <= 2*m+5 && visited[x*2] == 0){
            numb.push(2*x);
            dist[2*x] = dist[x] + 1;
        }
    }
    return dist[m];
}
int main(){
    ms(visited, 0, sizeof(visited));
    ms(dist, 0, sizeof(dist));
    cin>>n>>m;
    cout<<solve();
    return 0;
}
