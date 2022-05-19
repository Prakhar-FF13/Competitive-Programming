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
vii g[int(1e5) + 5];
vl dp, dist, minFlights, maxFlights;
vi visited;

void dijkstra()
{
  priority_queue<pll, vll, greater<pll> > pq;
  dist[1] = 0;       // distance to node 1.
  dp[1] = 1;         // number of ways to reach 1.
  minFlights[1] = 0; // min number of flights to get to node 1. (min edges to 1)
  maxFlights[1] = 0; // max number of flights to get to node 1. (max edges to 1)
  pq.push(mp(0, 1));

  while (!pq.empty())
  {
    pll z = pq.top();
    pq.pop();
    ll u = z.second;
    ll d = z.first;

    if (dist[u] < d)
      continue;

    rep(i, 0, g[u].size())
    {
      pll y = g[u][i];
      ll v = y.first;
      ll w = y.second;

      if (dist[v] < d + w)
        continue;
      // another path with same distance to v, update count.
      else if (dist[v] == d + w)
      {
        dp[v] = (dp[v] + dp[u]) % MOD;
        minFlights[v] = min(minFlights[v], minFlights[u] + 1);
        maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
      }
      else
      {
        dp[v] = dp[u] % MOD;
        dist[v] = d + w;
        minFlights[v] = minFlights[u] + 1;
        maxFlights[v] = maxFlights[u] + 1;
        pq.push(mp(dist[v], v));
      }
    }
  }

  cout << dist[n] << " " << dp[n] << " " << minFlights[n] << " " << maxFlights[n];
}

int main()
{
  // RW();
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].pb(mp(b, c));
  }
  visited.assign(n + 3, 0);
  dp.assign(n + 3, 0);
  dist.assign(n + 3, INF);
  minFlights.assign(n + 3, 0);
  maxFlights.assign(n + 3, 0);
  dijkstra();
  return 0;
}