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
vi parent;
vi dist;

void dijsktra()
{
  set<pii> pq;
  dist[1] = 0;
  rep(i, 1, n + 1)
      pq.insert(mp(dist[i], i));
  while (!pq.empty())
  {
    pii z = *pq.begin();
    int u = z.second;
    int d = z.first;
    pq.erase(pq.begin());
    if (dist[u] < d || d == int(1e9))
      continue;
    rep(i, 0, g[u].size())
    {
      int v = g[u][i];
      int w = -1;
      if (d + w > dist[v])
        continue;
      pq.erase(pq.find(mp(dist[v], v)));
      dist[v] = d + w;
      parent[v] = u;
      pq.insert(mp(dist[v], v));
    }
  }
  if (dist[n] == int(1e9))
  {
    cout << "IMPOSSIBLE";
    return;
  }
  int x = n;
  vi path;
  while (x != -1)
  {
    path.pb(x);
    x = parent[x];
  }
  reverse(all(path));
  cout << path.size() << endl;
  rep(i, 0, path.size()) cout << path[i] << " ";
}

int main()
{
  RW();
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
  }
  dist.assign(n + 3, int(1e9));
  parent.assign(n + 3, -1);
  dijsktra();
  return 0;
}