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

int n, m;
vii g[int(1e5) + 5];
vl dist;

void dijsktra(int x)
{
  set<pll> pq;
  rep(i, 1, n + 1)
      pq.insert(mp(dist[i], i));
  dist[x] = 0;

  while (!pq.empty())
  {
    pll z = *pq.begin();
    ll d = z.first;
    ll u = z.second;
    pq.erase(pq.begin());
    rep(i, 0, g[u].size())
    {
      pll neigh = g[u][i];
      ll v = neigh.first;
      ll ew = neigh.second;
      if (dist[u] + ew > dist[v])
        continue;
      pq.erase(pq.find(mp(dist[v], v)));
      dist[v] = dist[u] + ew;
      pq.insert(mp(dist[v], v));
    }
  }
}

int main()
{
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].pb(mp(b, c));
  }
  dist.assign(n + 5, ll(1e15));
  dijsktra(1);
  rep(i, 1, n + 1)
          cout
      << dist[i] << " ";
  return 0;
}