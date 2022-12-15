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

int n, k;
vector<int> arr(101);
ll dp[101][int(1e5 + 1)];
ll pre[101][int(1e5 + 1)];

int main()
{
  cin >> n >> k;
  rep(i, 0, n) cin >> arr[i];

  // initialize dp array.
  rep(i, 0, n + 1) rep(j, 0, k + 1) dp[i][j] = 0;

  // last kid, base case.
  for (int i = 0; i <= arr[n - 1]; i++)
    dp[n - 1][i] = 1;

  // for other kids.
  for (int i = n - 2; i >= 0; i--)
  {
    // calculate prefix sum of next row.
    pre[i + 1][0] = dp[i + 1][0];
    rep(j, 1, k + 1)
        pre[i + 1][j] = (pre[i + 1][j - 1] + dp[i + 1][j]) % MOD;

    // use prefix sum to get dp(i,j)
    rep(j, 0, k + 1)
    {
      if (j > arr[i])
        dp[i][j] = (pre[i + 1][j] + MOD - pre[i + 1][j - arr[i] - 1]) % MOD;
      else
        dp[i][j] = pre[i + 1][j];
    }
  }
  cout << dp[0][k];
  return 0;
}