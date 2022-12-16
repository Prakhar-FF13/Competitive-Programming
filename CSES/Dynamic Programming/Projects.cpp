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
  vector<pair<ll, pll> > arr(n);
  rep(i, 0, n)
  {
    int s, e, p;
    cin >> s >> e >> p;
    arr[i] = mp(e, mp(s, p));
  }
  sort(all(arr));
  ll dp[n]; // max reward we can get from 0...i interval.
  dp[0] = arr[0].second.second;

  for (int i = 1; i < n; i++)
  {
    ll l = 0, h = i - 1, ans = -1;
    while (l <= h)
    {
      ll m = l + (h - l) / 2;
      if (arr[i].second.first > arr[m].first)
      {
        ans = m;
        l = m + 1;
      }
      else
      {
        h = m - 1;
      }
    }
    dp[i] = max(dp[i-1], arr[i].second.second + (ans != -1 ? dp[ans] : 0));
  }
  cout << dp[n - 1];
  return 0;
}