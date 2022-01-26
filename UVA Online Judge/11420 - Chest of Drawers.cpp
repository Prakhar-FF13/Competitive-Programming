/*
  Good DP problem - Base case finding is good.
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

ll n, s;
ll dp[2][66][66];
ll solve(int prev, ll len, ll locks)
{
  if (len == n)
  {
    if (prev == 1)
      locks++;
    return locks == s;
  }
  else if (dp[prev][len][locks] != -1)
  {
    return dp[prev][len][locks];
  }
  else
  {
    return dp[prev][len][locks] = solve(0, len + 1, locks) + solve(1, len + 1, locks + (prev == 1));
  }
}

int main()
{
  RW();
  fsi;
  while (cin >> n >> s, n > 0)
  {
    rep(i, 0, 66) rep(j, 0, 66) dp[0][i][j] = dp[1][i][j] = -1;
    cout << solve(0, 0, 0) << endl;
  }
  return 0;
}