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
#include <iomanip>

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
#define repit(a) for (auto it = a.begin(); it != a.end(); it++)
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
  for (int xt = 1; xt <= t; xt++)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ms memset
#define get(t, ind) get<ind>(t)
#define all(v) v.begin(), v.end()
#define LSOne(x) x &(-x)
#define pob pop_back
#define NINF -ll(1e18)
#define INF ll(1e18)

int n, m;
vi g[int(1e5) + 5];
vi childToFollow;
vi dist;
vi visited;

void dfs(int u)
{
  visited[u] = 1;
  if (u == n)
  {
    dist[n] = 0;
    return;
  }
  rep(i, 0, g[u].size())
  {
    int v = g[u][i];
    if (visited[v] == 0)
      dfs(v);
    if (dist[v] == -1)
      continue;
    if (1 + dist[v] > dist[u])
    {
      dist[u] = 1 + dist[v];
      childToFollow[u] = v;
    }
  }
}

int main()
{
  // RW();
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
  }
  dist.assign(n + 3, -1);
  childToFollow.assign(n + 3, -1);
  visited.assign(n + 3, 0);
  dfs(1);
  if (dist[n] == -1)
  {
    cout << "IMPOSSIBLE";
    return 0;
  }
  int x = 1;
  vi path;
  while (x != n)
  {
    path.pb(x);
    x = childToFollow[x];
  }
  cout << path.size() + 1 << endl;
  rep(i, 0, path.size()) cout << path[i] << " ";
  cout << n;
  return 0;
}