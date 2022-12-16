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

vector<double> arr(3000);
double dp[3000][3000];
int n;

int main()
{
  cin >> n;
  rep(i, 0, n) cin >> arr[i];
  rep(i, 0, n + 1)
      rep(j, 0, n + 1)
          dp[i][j] = 0;

  dp[0][0] = 1;
  dp[1][0] = 1 - arr[0];
  dp[1][1] = arr[0];
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (j == 0)
        dp[i][j] = dp[i - 1][j] * (1 - arr[i - 1]);
      else
        dp[i][j] = dp[i - 1][j - 1] * arr[i - 1] + dp[i - 1][j] * (1 - arr[i - 1]);
    }
  }

  double ans = 0;
  for (int i = n / 2 + 1; i <= n; i++)
    ans += dp[n][i];

  printf("%.10f", ans);
  return 0;
}