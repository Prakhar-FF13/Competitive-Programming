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

typedef struct Edge
{
  ll a, b, w;

  Edge(ll u, ll v, ll x)
  {
    a = u;
    b = v;
    w = x;
  }
} E;
int n, m;
vector<E> g;
vl dist;
int main()
{
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b, w;
    cin >> a >> b >> w;
    E x = *(new E(a, b, -w));
    g.pb(x);
  }
  dist.assign(n + 1, ll(1e15));
  dist[1] = 0;
  // relax n-1 times.
  rep(j, 0, n - 1)
  {
    rep(i, 0, g.size())
    {
      E x = g[i];
      if (dist[x.a] == ll(1e15))
        continue;
      dist[x.b] = min(dist[x.b], dist[x.a] + x.w);
    }
  }
  // relax n-1 times more, if weight changes -> -ve cycle.
  rep(j, 0, n - 1)
  {
    rep(i, 0, g.size())
    {
      E x = g[i];
      if (dist[x.a] == ll(1e15))
        continue;
      if (dist[x.b] > dist[x.a] + x.w)
        dist[x.b] = -ll(1e15);
    }
  }
  if (dist[n] == -ll(1e15))
    cout << -1;
  else
    cout << -dist[n];
  return 0;
}