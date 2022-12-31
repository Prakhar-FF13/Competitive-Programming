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
int mat[11][101];
ll dp[(1 << 11)][111];

ll s(int mask, int i)
{
  if (mask == ((1 << n) - 1))
    return dp[mask][i] = 1;
  if (i > 100)
    return 0;
  if (dp[mask][i] != -1)
    return dp[mask][i];
  ll ans = 0;
  ans += s(mask, i + 1) % MOD;
  for (int j = 0; j < n; j++)
  {
    if (((mask & (1 << j)) == 0) && mat[j][i] == 1)
      ans = (ans + s(mask | (1 << j), i + 1) % MOD) % MOD;
  }
  return dp[mask][i] = ans;
}

int main()
{
  RW()
  tt()
  {
    cin >> n;
    ms(mat, 0, sizeof(mat));
    ms(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
      string s;
      getline(cin >> ws, s);
      istringstream is(s);
      int x;
      while (is >> x)
        mat[i][x] = 1;
    }
    cout << s(0, 1) << endl;
  }
  return 0;
}