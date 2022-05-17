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
#define NINF -ll(1e15)
#define INF ll(1e15)

int n, m;
vll g[2550];
vl dist;
vl parent;

void bellmanFord()
{
  ll x;
  // n-1 iteration, wont detect -ve cycle but nth iteration does.
  rep(k, 0, n) // n iterations will detect -ve cycle or not.
  {
    x = -1;
    rep(i, 0, n + 1)
    {
      rep(j, 0, g[i].size())
      {
        pll y = g[i][j];
        ll v = y.first;
        ll w = y.second;

        if (dist[v] > dist[i] + w)
        {
          x = v;
          dist[v] = dist[i] + w;
          parent[v] = i;
        }
      }
    }
  }
  // no change in weights in nth iteration -> no -ve cycle.
  if (x == -1)
  {
    cout << "NO";
    return;
  }
  cout << "YES" << endl;
  // cycle present.
  // traceback n-1 times to reach a vertex in -ve cycle.
  rep(i, 0, n - 1)
      x = parent[x];

  // traceback until x is reached again to get cycle.
  vl cycle;
  ll v = x;
  while (true)
  {
    cycle.pb(x);
    x = parent[x];
    if (x == v)
    {
      cycle.pb(x);
      break;
    }
  }
  // reverse to egt cycle.
  reverse(all(cycle));
  rep(i, 0, cycle.size())
          cout
      << cycle[i] << " ";
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
  rep(i, 1, n + 1) g[0].pb(mp(i, 0));
  // so that we only relax on negative edges, otherwise INF is initialized.
  // this allows us to only deal with -ve cycles.
  // we dont need to do 2 (n - 1) iters before detecting cycle.
  dist.assign(n + 3, 0);
  parent.assign(n + 3, -1);
  bellmanFord();
  return 0;
}