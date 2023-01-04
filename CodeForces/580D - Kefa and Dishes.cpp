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

int n, m, k;
ll rule[111][111];
ll dp[20][1 << 20];
vector<ll> arr(20);

ll s(int prev, int mask)
{
  if (__builtin_popcount(mask) == m + 1)
  {
    // cout << prev << " " << mask << endl;
    return 0;
  }
  if (dp[prev][mask] != -1)
    return dp[prev][mask];
  ll ans = 0;
  for (int j = 1; j <= n; j++)
  {
    if ((mask & (1 << j)) == 0)
      ans = max(ans, s(j, mask | (1 << j)) + rule[prev][j] + arr[j]);
  }
  return dp[prev][mask] = ans;
}

int main()
{
  RW();
  cin >> n >> m >> k;
  rep(i, 1, n + 1) cin >> arr[i];
  ms(rule, 0, sizeof(rule));
  ms(dp, -1, sizeof(dp));
  rep(i, 0, k)
  {
    int x, y, c;
    cin >> x >> y >> c;
    rule[x][y] = c;
  }
  cout << s(0, 1);
  return 0;
}