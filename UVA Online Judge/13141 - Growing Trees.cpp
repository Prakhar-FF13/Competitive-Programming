/*
  Great DP Question - Bottom up thinking, "recursive thinking" does not work here.
  Recursive thinking does not work but recursion is observable.
  Must solve. Similar to maximum product sum dp. (state is similar)
*/
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
#define LSOne(x) x &(-x)
#define pob pop_back

ll l;

int main()
{
  RW();
  fsi;
  // lvl,0 -> incoming branches at this lvl.
  // lvl,1 -> branches that have to branch at this lvl.
  // lvl,2 -> branches that do not have to branch at this lvl.
  ll dp[86][3];
  dp[0][0] = dp[0][1] = dp[0][2] = 0;
  dp[1][0] = dp[1][1] = dp[1][2] = 0;
  dp[1][0] = 1;
  dp[1][1] = 0;
  dp[1][2] = 1;
  rep(i, 2, 86)
  {
    dp[i][0] = 2 * dp[i - 1][1] + dp[i - 1][2];
    dp[i][1] = dp[i - 1][2] + dp[i - 1][1];
    dp[i][2] = dp[i - 1][1];
  }
  while (cin >> l, l)
  {
    cout << dp[l][0] << endl;
  }
  return 0;
}