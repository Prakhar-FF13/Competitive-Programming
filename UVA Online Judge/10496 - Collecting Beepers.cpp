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

int n;
int dist[13][13];
int dp[13][1 << 13];
vii pcs;

int TSP(int u, int mask)
{
  if (mask == 0)
    return dist[u][0];
  if (dp[u][mask] != -1)
    return dp[u][mask];
  int m = mask;
  int ans = 1e9;
  while (m > 0)
  {
    int x = LSOne(m);
    int y = __builtin_ctz(x) + 1;
    int d = TSP(y, mask ^ x);
    if (dist[u][y] + d < ans)
    {
      ans = dist[u][y] + d;
    }
    m -= x;
  }
  return dp[u][mask] = ans;
}

int runTSP()
{
  rep(i, 0, 13)
  {
    rep(j, 0, (1 << 13))
    {
      dp[i][j] = -1;
    }
  }
  return TSP(0, (1 << n) - 1);
}

int main()
{
  RW();
  fsi;
  tt()
  {
    pcs.clear();
    int sx, sy;
    cin >> sx >> sy;
    int x, y;
    cin >> x >> y;
    pcs.pb(mp(x, y));
    cin >> n;
    rep(i, 0, n)
    {
      cin >> x >> y;
      pcs.pb(mp(x, y));
    }
    rep(i, 0, n + 1)
    {
      rep(j, 0, n + 1)
      {
        dist[i][j] = abs(pcs[i].first - pcs[j].first) + abs(pcs[i].second - pcs[j].second);
        dist[j][i] = dist[i][j];
      }
      dist[i][i] = MOD;
    }
    cout << "The shortest path has length " << runTSP() << endl;
  }
  return 0;
}