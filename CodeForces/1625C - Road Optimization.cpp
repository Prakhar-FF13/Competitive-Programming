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

int n, K, l;
vector<ll> coord, limits;

ll dp[501][501];

ll s(int i, int k)
{
  if (i >= n)
    return 0;
  if (dp[i][k] != -1)
    return dp[i][k];
  else
  {
    ll ans = 1e18;
    rep(j, i + 1, n + 1)
    {
      if (k - (j - i - 1) >= 0)
        ans = min(ans, s(j, k - (j - i - 1)) + (limits[i] * (coord[j] - coord[i])));
    }
    return dp[i][k] = ans;
  }
}

int main()
{
  RW()
  cin >> n >> l >> K;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    coord.pb(x);
  }
  coord.pb(l);
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    limits.pb(x);
  }
  rep(i, 0, 501)
      rep(j, 0, 501)
          dp[i][j] = -1;
  cout << s(0, K);
}