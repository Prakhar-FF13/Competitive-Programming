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
#define LSOne(x) x & (-x)
#define pob pop_back

int n;
int a[22][22];
ll dp[22][1 << 22];

ll s(int m, int mask)
{
  if (mask == ((1 << n) - 1))
    return 1;
  if (m < 0)
    return 0;
  if (dp[m][mask] != -1)
    return dp[m][mask];
  ll ans = 0;
  for (int j = 0; j < n; j++)
  {
    if (a[m][j] && (mask & (1 << j)) == 0)
      ans = (ans + s(m - 1, mask | (1 << j))) % MOD;
  }
  return dp[m][mask] = ans;
}

int main()
{
  RW();
  cin >> n;
  rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
  ms(dp, -1, sizeof(dp));
  cout << s(n - 1, 0);
  return 0;
}