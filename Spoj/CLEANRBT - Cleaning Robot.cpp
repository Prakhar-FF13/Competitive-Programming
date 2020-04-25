#include <iostream>
#include <cstdio>
#include <string.h>
#include <climits>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)
#define fsi                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);
#define RW()                       \
  freopen("read.txt", "r", stdin); \
  freopen("write.txt", "w", stdout);
#define MOD 1000000007
#define tt() \
  int t;     \
  cin >> t;  \
  while (t--)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ms memset
#define get(t, ind) get<ind>(t)
#define all(v) v.begin(), v.end()
#define pob pop_back
 
int r, c, cities;
char grid[25][25]; // grid of characters
int dist[12][12];  // distance matrix
 
void bfs(int i, int j) {
  cities++;
  queue<pii> q;
  q.push({i, j});
  int distX = grid[i][j] != 'm' ? grid[i][j] - '0' : 10, dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1}, cost[25][25];
  bool visited[25][25];
  rep(k, 0, 25)
    rep(l, 0, 25)
      visited[k][l] = false;
  visited[i][j] = true;
  cost[i][j] = 0;
  while(!q.empty()) {
    pii x = q.front();
    q.pop();
    rep(k, 0, 4) {
      int nx = dx[k] + x.first, ny = dy[k] + x.second;
      if (nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny] && grid[nx][ny] != 'x') {
        cost[nx][ny] = cost[x.first][x.second] + 1;
        visited[nx][ny] = true;
        q.push({nx, ny});
        if (grid[nx][ny] >= '0' && grid[nx][ny] <= '9') 
          dist[distX][grid[nx][ny] - '0'] = cost[nx][ny];
        else if (grid[nx][ny] == 'm')
          dist[distX][10] = cost[nx][ny];
      }
    }
  }
}
 
int dp[10000][25];
 
int tsp(int mask, int pos) {
  if (mask == ((1<<cities) - 1)) 
    return 0;
 
  if (dp[mask][pos] != 1e9)
    return dp[mask][pos];
 
  int ans = 1e9;
  rep(i, 0, cities) {
    if (mask & (1<<i)) continue;
  
    ans = min(ans, dist[pos][i] + tsp(mask | (1<<i), i));
  }
  return dp[mask][pos] = ans;
}
 
int main() {
  RW()
  while (cin >> c >> r) {
    if (r == 0 || c == 0) break;
    rep(i, 0, 12)
      rep(j, 0, 12)
        dist[i][j] = 1e9;
    char dirtyCount = '1';
    cities = 0;
    rep(i, 0, r)
      rep(j, 0, c){
        cin >> grid[i][j];
        if (grid[i][j] == 'o')
          grid[i][j] = '0';
        else if (grid[i][j] == '*') {
          if (dirtyCount == 'X')
            grid[i][j] = 'm';
          else {
            grid[i][j] = dirtyCount;
            if (dirtyCount == '9')  dirtyCount = 'X';
            else dirtyCount++;
          }
        }
      }
 
    rep(i, 0, r){
      rep(j, 0, c){
        if ((grid[i][j] >= '0' && grid[i][j] <= '9') || grid[i][j] == 'm')
          bfs(i, j);
      }
    }

    rep(i, 0, 10000)
      rep(j, 0, 25)
        dp[i][j] = 1e9;
    
    int ans = tsp(1<<0, 0);
    if(ans == 1e9)
      cout<<-1<<endl;
    else
      cout<<ans<<endl;
  }
  return 0;
}