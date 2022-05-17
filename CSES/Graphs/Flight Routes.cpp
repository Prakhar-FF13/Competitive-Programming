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

int n, m, k;
vll g[int(1e5) + 5];
// store k distances.
ll dist[int(1e5) + 5][11];

void dijsktra()
{
  priority_queue<pll, vll, greater<pll> > pq;
  pq.push(mp(0, 1));

  while (!pq.empty())
  {
    pll z = pq.top();
    pq.pop();
    ll u = z.second;
    ll d = z.first;
    // no point expanding this path.
    if (dist[u][k] < d)
      continue;

    rep(i, 0, g[u].size())
    {
      pll y = g[u][i];
      ll v = y.first;
      ll w = y.second;

      // current max distance is greater than distance through this node, change.
      if (dist[v][k] > d + w)
      {
        dist[v][k] = d + w;
        pq.push(mp(dist[v][k], v));
        sort(dist[v], dist[v] + (k + 1));
      }
    }
  }
  rep(i, 0, k + 1)
          cout
      << dist[n][i] << " ";
}

int main()
{
  // RW();
  cin >> n >> m >> k;
  k--;
  rep(i, 0, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].pb(mp(b, c));
  }
  rep(i, 0, n + 3) rep(j, 0, 11) dist[i][j] = INF;
  dijsktra();
  return 0;
}