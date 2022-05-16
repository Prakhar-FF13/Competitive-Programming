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
vll g[int(1e5) + 5], rg[int(1e5) + 5];
vl dist1, dist2;

void dijsktra(int x, vl &dis, vll graph[])
{
  set<pll> pq;
  dis[x] = 0;
  rep(i, 1, n + 1)
      pq.insert(mp(dis[i], i));

  while (!pq.empty())
  {
    pll y = *pq.begin();
    pq.erase(pq.begin());
    ll d = y.first;
    ll u = y.second;

    rep(i, 0, graph[u].size())
    {
      pii z = graph[u][i];
      ll v = z.first;
      ll w = z.second;

      if (dis[v] > d + w)
      {
        pq.erase(pq.find(mp(dis[v], v)));
        dis[v] = d + w;
        pq.insert(mp(dis[v], v));
      }
    }
  }
}

int main()
{
  // RW();
  cin >> n >> m;
  rep(i, 0, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    g[a].pb(mp(b, c));
    rg[b].pb(mp(a, c));
  }
  dist1.assign(n + 2, 1e15 + 7);
  dist2.assign(n + 2, 1e15 + 7);
  dijsktra(1, dist1, g);
  dijsktra(n, dist2, rg);

  ll ans = 1e15;

  rep(i, 1, n + 1)
  {
    rep(j, 0, g[i].size())
    {
      ll x = dist1[i] + dist2[g[i][j].first] + (g[i][j].second / 2);
      ans = min(ans, x);
    }
  }

  cout << ans;

  return 0;
}