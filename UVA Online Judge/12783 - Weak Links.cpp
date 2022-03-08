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

vector<vector<int> > g(1001);
vi dfs_num, dfs_low, dfs_parent, visited;
vii weakLinks;
int dfsCounter, n, m;

void clear()
{
  rep(i, 0, 1001)
      g[i]
          .clear();
  dfs_low.assign(1001, -1);
  dfs_num.assign(1001, -1);
  dfs_parent.assign(1001, -1);
  visited.assign(1001, 0);
  weakLinks.clear();
  dfsCounter = 1;
}

void dfs(int u)
{
  visited[u] = 1;
  dfs_num[u] = dfs_low[u] = dfsCounter++;

  rep(i, 0, g[u].size())
  {
    int v = g[u][i];
    if (!visited[v])
    {
      dfs_parent[v] = u;
      dfs(v);

      if (dfs_num[u] < dfs_low[v])
      {
        weakLinks.pb(mp(min(u, v), max(u, v)));
      }
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if (dfs_parent[u] != v)
    {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

int main()
{
  RW();
  fsi;
  while (cin >> n >> m, n)
  {
    clear();
    rep(i, 0, m)
    {
      int a, b;
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
    }
    rep(i, 0, n) if (!visited[i])
        dfs(i);

    sort(all(weakLinks));

    cout << weakLinks.size();
    rep(i, 0, weakLinks.size())
    {
      cout << " " << weakLinks[i].first << " " << weakLinks[i].second;
    }
    cout << endl;
  }
  return 0;
}