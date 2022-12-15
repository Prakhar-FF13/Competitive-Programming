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

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  rep(i, 0, n) cin >> arr[i];
  int sum = 0;
  rep(i, 0, n) sum += arr[i];
  vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, 0));
  rep(i, 0, sum + 1) dp[0][i] = 0;
  rep(i, 0, n + 1) dp[i][0] = 1;
  rep(i, 1, n + 1)
  {
    rep(j, 1, sum + 1)
    {
      dp[i][j] = dp[i - 1][j];
      if (j - arr[i - 1] >= 0)
        dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= sum; i++)
    cnt += dp[n][i];
  cout << cnt << endl;
  for (int i = 1; i <= sum; i++)
    if (dp[n][i])
      cout << i << " ";
}