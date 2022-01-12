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
double dist[10][10];
double dp[11][1 << 11];
int nxt[11][1 << 11];
vii pcs;

double euclidean(pii x, pii y)
{
  return sqrt(((x.first - y.first) * (x.first - y.first)) +
              ((x.second - y.second) * (x.second - y.second)));
}

// tsp(0, (1<<(n-1)) -1) , 0 is assumed to be visited.
double TSP(int u, int mask)
{
  if (mask == 0)
    return 0;
  if (dp[u][mask] != -1)
    return dp[u][mask];
  int m = mask;
  double ans = 1e9;
  while (m > 0)
  {
    int x = LSOne(m);
    int y = __builtin_ctz(x) + 1;
    double d = TSP(y, mask ^ x);
    if (dist[u][y] + d < ans)
    {
      ans = dist[u][y] + d;
      nxt[u][mask] = y;
    }
    m -= x;
  }
  return dp[u][mask] = ans;
}

double runTSP()
{
  rep(i, 0, 11)
  {
    rep(j, 0, (1 << 11))
    {
      dp[i][j] = -1;
      nxt[i][j] = -1;
    }
  }
  return TSP(0, (1 << (n - 1)) - 1);
}

void printNetwork(double tot, int xt)
{
  int prev = 0;
  cout << "**********************************************************" << endl;
  cout << "Network #" << xt << endl;
  int m = (1 << (n - 1)) - 1;
  cout << std::fixed << std::showpoint;
  cout << std::setprecision(2);
  while (nxt[prev][m] != -1)
  {
    cout << "Cable requirement to connect (" << pcs[prev].first << "," << pcs[prev].second << ") to (";
    cout << pcs[nxt[prev][m]].first << "," << pcs[nxt[prev][m]].second << ") is ";
    cout << dist[prev][nxt[prev][m]] << " feet." << endl;
    prev = nxt[prev][m];
    m = m ^ (1 << (prev - 1));
  }
  cout << "Number of feet of cable required is " << tot << "." << endl;
}

void swapRow(int x)
{
  swap(pcs[0], pcs[x]);
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      dist[i][j] = euclidean(pcs[i], pcs[j]) + 16;
      dist[j][i] = dist[i][j];
    }
    dist[i][i] = MOD;
  }
}

int main()
{
  RW();
  fsi;
  int xt = 1;
  while (cin >> n, n)
  {
    pcs.clear();
    rep(i, 0, n)
    {
      int x, y;
      cin >> x >> y;
      pcs.pb(mp(x, y));
    }
    rep(i, 0, n)
    {
      rep(j, 0, n)
      {
        dist[i][j] = euclidean(pcs[i], pcs[j]) + 16;
        dist[j][i] = dist[i][j];
      }
      dist[i][i] = MOD;
    }
    double ans = 1e9, start = -1;
    rep(i, 0, n)
    {
      swapRow(i);
      double tot = runTSP();
      swapRow(i);
      if (tot < ans)
      {
        start = i;
        ans = tot;
      }
    }
    swapRow(start);
    double tot = runTSP();
    printNetwork(tot, xt);
    xt++;
  }
  return 0;
}