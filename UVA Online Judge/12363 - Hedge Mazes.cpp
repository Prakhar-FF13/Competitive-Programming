/*
  Good problem - Graphs (finding bridges) + DSU
*/
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

int r, c, q;
vector<vector<int> > g(10001);
vector<vector<int> > gp(10001);
vector<int> visited(10001), dfs_low(10001), dfs_num(10001), dfs_parent(10001);
int dfsCounter = 1;

class DSU
{
private:
  vi parent, rank;

public:
  DSU()
  {
    rep(i, 0, 10001)
    {
      parent.pb(i);
      rank.pb(1);
    }
  }
  int findSet(int u)
  {
    int x = u;
    while (parent[x] != x)
      x = parent[x];
    return x;
  }
  void unionSet(int u, int v)
  {
    int pu = findSet(u);
    int pv = findSet(v);
    if (pu == pv)
      return;
    if (rank[pu] <= rank[pv])
    {
      parent[pu] = pv;
      if (rank[pu] == rank[pv])
        rank[pv]++;
    }
    else
    {
      parent[pv] = pu;
    }
  }
};

DSU du;

void clear()
{
  rep(i, 0, 10001)
  {
    g[i].clear();
    gp[i].clear();
  }
}

void clearVisited()
{
  visited.assign(10001, 0);
  dfs_low.assign(10001, 0);
  dfs_num.assign(10001, 0);
  dfs_parent.assign(10001, -1);
  dfsCounter = 1;
  du = *(new DSU());
}

void createGP(int u)
{
  dfs_num[u] = dfs_low[u] = dfsCounter++;
  visited[u] = 1;
  rep(i, 0, g[u].size())
  {
    int v = g[u][i];
    if (!visited[v])
    {
      dfs_parent[v] = u;
      createGP(v);

      if (dfs_low[v] > dfs_num[u])
      {
        gp[u].pb(v);
        gp[v].pb(u);
        du.unionSet(u, v);
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
  while (cin >> r >> c >> q, r)
  {
    clear();
    clearVisited();
    while (c--)
    {
      int a, b;
      cin >> a >> b;
      g[a].pb(b);
      g[b].pb(a);
    }
    rep(i, 1, r + 1)
    {
      if (!visited[i])
        createGP(i);
    }
    while (q--)
    {
      int a, b;
      cin >> a >> b;
      int pa = du.findSet(a);
      int pb = du.findSet(b);
      if (pa == pb)
        cout << "Y" << endl;
      else
        cout << "N" << endl;
    }
    cout << "-" << endl;
  }
  return 0;
}