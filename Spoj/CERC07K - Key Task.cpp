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
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back
int r,c;
char arr[101][101];
int visited[101][101][20], cost[101][101][20];
int si, sj;
vector<pii> endsp;

void pre() {
  endsp.clear();
  rep(i, 0, r)
    rep(j, 0, c) {
      if (arr[i][j] == '*') si = i, sj = j;
      if (arr[i][j] == 'X') endsp.push_back({i, j});
      rep(k, 0, 20)
        visited[i][j][k] = 0, cost[i][j][k] = 1e9;
    }
}

bool allowed(int i, int j, int &st) {
  switch(arr[i][j]) {
    case 'R': if (st & (1<<0))  return true; else return false;
    case 'G': if (st & (1<<1))  return true; else return false;
    case 'B': if (st & (1<<2))  return true; else return false;
    case 'Y': if (st & (1<<3))  return true; else return false;
    case 'r': st = st | (1<<0); return true;
    case 'g': st = st | (1<<1); return true;
    case 'b': st = st | (1<<2); return true;
    case 'y': st = st | (1<<3); return true;
    case '#': return false;
    case '.': return true;
    case '*': return true;
    case 'X': return true;
  }
  return false;
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int i, int j) {
  queue<pair<int, pii> > q;
  q.push({0, {i, j}});
  cost[i][j][0] = 0;
  visited[i][j][0] = 1;
  while(!q.empty()) {
    pair<int,pii> top = q.front();
    q.pop();
    int st = top.first, x = top.second.first, y = top.second.second;
    rep(i, 0, 4) {
      rep(j, 0, 4) {
        int nx = dx[i] + x, ny = dy[i] + y;
        st = top.first;
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && allowed(nx, ny, st)) {
          if (!visited[nx][ny][st]) {
            visited[nx][ny][st] = 1;
            q.push({st, {nx, ny}});
            cost[nx][ny][st] = min(cost[nx][ny][st], cost[x][y][top.first]+1);
          }
        }
      }
    } 
  }
}

int main(){
  RW()
  while(cin>>r>>c){
    if(r==0)  break;
    rep(i, 0, r)
      rep(j, 0, c)
        cin>>arr[i][j];

    pre();
    bfs(si, sj);
    int ans = 1e9;
    rep(i, 0, endsp.size()) {
      pii x = endsp[i];
      rep(j, 0, 20)
        ans = min(ans, cost[x.first][x.second][j]);
    }
    if (ans != 1e9)
      cout<<"Escape possible in "<<ans<<" steps."<<endl;
    else
      cout<<"The poor student is trapped!"<<endl;
  } 
  return 0;
}
