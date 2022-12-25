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
  // RW();
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, 0, n - 1) cin >> a[i];
  rep(i, 0, n - 1) cin >> b[i];
  int dp[n][2];
  dp[0][0] = 0;
  dp[0][1] = c;
  cout << 0;
  for (int i = 1; i < n; i++)
  {
    dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
    dp[i][1] = min(dp[i - 1][0] + c + b[i - 1], dp[i - 1][1] + b[i - 1]);
    cout << " " << min(dp[i][0], dp[i][1]);
  }
  return 0;
}