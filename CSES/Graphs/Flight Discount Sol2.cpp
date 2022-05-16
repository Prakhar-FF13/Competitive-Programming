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
vll g[int(1e5) + 5];
ll dist[int(1e5) + 5][2];

struct Triple
{
  ll d, a, c;
  Triple(ll x, ll y, ll z)
  {
    d = x;
    a = y;
    c = z;
  }
};
struct TripleComp
{
  bool operator()(const Triple t1, const Triple t2)
  {
    return t1.d < t2.d;
  }
};

void dijsktra()
{
  dist[1][0] = dist[1][1] = 0;
  priority_queue<Triple, vector<Triple>, TripleComp> pq;
  pq.push(Triple(0, 1, 0));
  while (!pq.empty())
  {
    Triple t = pq.top();
    pq.pop();

    if (dist[t.a][t.c] < t.d)
      continue;

    rep(i, 0, g[t.a].size())
    {
      pll x = g[t.a][i];
      ll v = x.first;
      ll w = x.second;
      // use coupon if possible.
      if (t.c == 0 && dist[v][1] > dist[t.a][t.c] + (w / 2))
      {
        dist[v][1] = dist[t.a][t.c] + (w / 2);
        pq.push(Triple(dist[v][1], v, 1));
      }
      // normal way, irrespective of coupon or not.
      if (dist[v][t.c] > dist[t.a][t.c] + w)
      {
        dist[v][t.c] = dist[t.a][t.c] + w;
        pq.push(Triple(dist[v][t.c], v, t.c));
      }
    }
  }
  cout << dist[n][1];
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
  }
  rep(i, 0, n + 3)
      dist[i][0] = dist[i][1] = 1e15 + 7;
  dijsktra();
  return 0;
}