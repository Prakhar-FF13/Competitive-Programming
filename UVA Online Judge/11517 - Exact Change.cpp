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

int P, n;
int coins[101];
ll dp[30001];

// each coin can be used only once.
void CoinChange()
{
  rep(i, 0, 30001)
  {
    dp[i] = 1e9;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++)
  {
    int C = coins[i];
    for (int v = 30001 - C - 1; v >= 0; v--)
    {
      if (dp[v] != 1e9)
        dp[v + C] = min(dp[v + C], dp[v] + 1);
    }
  }
  int ans = 1e9;
  rep(i, P, 30001)
  {
    if (dp[i] != 1e9)
    {
      ans = i;
      break;
    }
  }
  cout << ans << " " << dp[ans] << endl;
}

int main()
{
  RW()
  tt()
  {
    cin >> P;
    cin >> n;
    rep(i, 0, n)
    {
      cin >> coins[i];
    }
    CoinChange();
  }
  return 0;
}