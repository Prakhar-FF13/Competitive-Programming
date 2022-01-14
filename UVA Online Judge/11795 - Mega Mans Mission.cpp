/*
  Tags - DP
  TSP DP variation - count number of paths.
*/
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
string arr[18];
ll dp[18][1 << 18];
int numb[18];

ll TSP(int u, int mask, int canDestroy)
{
  if (mask == 0)
    return 1;
  if (dp[u][mask] != -1)
    return dp[u][mask];
  int m = mask;
  ll ans = 0;
  while (m)
  {
    int two_pow_v = LSOne(m);
    int v = __builtin_ctz(two_pow_v) + 1;

    if (canDestroy & (1 << v))
      ans += TSP(v, mask ^ two_pow_v, canDestroy | (numb[v]));

    m -= two_pow_v;
  }
  return dp[u][mask] = ans;
}

ll runTSP()
{
  rep(i, 0, 18)
      rep(j, 0, (1 << 18))
          dp[i][j] = -1;

  return TSP(0, (1 << n) - 1, numb[0]);
}

int getNumber(string str)
{
  int ans = 0;
  rep(i, 0, str.length())
  {
    if (str[i] == '1')
      ans += (1 << i);
  }
  return ans;
}

int main()
{
  RW();
  fsi;
  tt()
  {
    cin >> n;
    rep(i, 0, n + 1)
    {
      string x;
      cin >> x;
      arr[i] = "0" + x;
      numb[i] = getNumber(arr[i]);
    }
    cout << "Case " << xt << ": " << runTSP() << endl;
  }
  return 0;
}