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
typedef vector<ll> vl;
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
int n,m,k;
string maze[510];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
map<pii, bool> visited;
bool valid(pii x){
    if(x.first < 0 || x.first >= n)
        return false;
    if(x.second < 0 || x.second >= m)
        return false;
    if(maze[x.first][x.second] != '.')
        return false;
    return true;
}
void dfs(pii src){
    visited[src] = true;
    rep(i, 0, 4){
        pii x = {src.first + dx[i], src.second + dy[i]};
        if(valid(x) && visited[x] == 0)
            dfs(x);
    }
    if(k > 0){
        k--;
        maze[src.first][src.second] = 'X';
    }
}
int main(){
    cin>>n>>m>>k;
    rep(i, 0, n)
        cin>>maze[i];
    rep(i, 0, n){
        if(k == 0)  break;
        rep(j, 0, m){
            if(maze[i][j] == '.'){
                dfs({i, j});
                break;
            }
        }
    }
    rep(i, 0, n)
        cout<<maze[i]<<endl;
    return 0;
}
