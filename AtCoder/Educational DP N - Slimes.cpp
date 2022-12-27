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
vector<ll> arr, pre;
ll dp[402][402];

int main()
{
  RW();
  cin >> n;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    arr.pb(x);
    if (i == 0)
      pre.pb(x);
    else
      pre.pb(x + pre[i - 1]);
  }
  rep(i, 0, 402) rep(j, 0, 402) dp[i][j] = ll(1e15);
  rep(i, 0, n) dp[i][i] = 0;
  rep(i, 0, n - 1) dp[i][i + 1] = arr[i] + arr[i + 1];

  rep(len, 2, n + 1)
  {
    rep(i, 0, n)
    {
      int j = i + len - 1;
      if (j >= n)
        break;
      rep(k, i, j)
      {
        ll cost = pre[j];
        if (i > 0)
          cost -= pre[i - 1];
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
      }
    }
  }
  cout << dp[0][n - 1];
  return 0;
}