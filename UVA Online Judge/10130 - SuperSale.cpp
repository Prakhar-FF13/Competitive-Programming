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
#define pob pop_back

vii arr;
int n, g;

int dp[1005][105];
int solve(int ipx, int wt)
{
  if (ipx == n || wt < 0)
    return 0;

  if (dp[ipx][wt] != -1)
    return dp[ipx][wt];
  int p = solve(ipx + 1, wt);
  int r = 0;

  if (arr[ipx].second <= wt)
    r = arr[ipx].first + solve(ipx + 1, wt - arr[ipx].second);

  return dp[ipx][wt] = max(p, r);
}

int main()
{
  fsi;
  RW();
  tt()
  {
    arr.clear();

    cin >> n;
    rep(i, 0, n)
    {
      int p, w;
      cin >> p >> w;
      arr.pb(mp(p, w));
    }

    cin >> g;
    int ans = 0;
    rep(i, 0, g)
    {
      ms(dp, -1, sizeof(dp));
      int x;
      cin >> x;
      ans += solve(0, x);
    }

    cout << ans << endl;
  }
  return 0;
}