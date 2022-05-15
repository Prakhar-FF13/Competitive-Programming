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

int n, m, q;
ll dist[501][501];

void floydWarshall()
{
  rep(k, 0, n)
      rep(i, 0, n)
          rep(j, 0, n)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
  cin >> n >> m >> q;
  rep(i, 0, n + 1)
      rep(j, 0, n + 1)
          dist[i][j] = ll(1e15);

  rep(i, 0, n + 1)
      dist[i][i] = 0;
  rep(i, 0, m)
  {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a - 1][b - 1] = dist[b - 1][a - 1] = min(dist[a - 1][b - 1], 1LL * c);
  }
  floydWarshall();
  rep(i, 0, q)
  {
    int a, b;
    cin >> a >> b;
    ll x = dist[a - 1][b - 1];
    if (x >= ll(1e15))
      cout << -1 << endl;
    else
      cout << x << endl;
  }
  return 0;
}