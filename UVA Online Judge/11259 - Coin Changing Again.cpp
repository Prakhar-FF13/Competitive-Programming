/*
  Tags - DP Very Good Problem - DP + Inclusion Exclusion
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

#define inf (int)1e9

ll coin[4], numb[4];
ll dp[int(1e5) + 5];

// coin change with infinite coins.
void initialize()
{
  rep(i, 0, 1e5 + 5)
  {
    dp[i] = 0;
  }
  dp[0] = 1;
  rep(i, 0, 4)
  {
    rep(j, coin[i], 1e5 + 5)
    {
      dp[j] += dp[j - coin[i]];
    }
  }
}

ll getResult(ll v)
{
  ll ans = dp[v];
  // generate permuattion of 4 numbers(coins)
  for (int i = 1; i <= 15; i++)
  {
    ll j = 0;
    ll sign = 1;
    ll Val = 0;
    while ((1 << j) <= i)
    {
      if (i & (1 << j))
      {
        sign = -sign;
        Val += (numb[j] + 1) * coin[j];
      }
      j++;
    }
    if (v - Val >= 0)
      ans += sign * dp[v - Val];
  }

  return ans;
}

int main()
{
  RW()
  fsi;
  int N;
  cin >> N;
  while (N--)
  {
    rep(i, 0, 4)
    {
      cin >> coin[i];
    }
    ll q;
    cin >> q;
    initialize();
    while (q--)
    {
      rep(i, 0, 4)
      {
        cin >> numb[i];
      }
      ll v;
      cin >> v;
      cout << getResult(v) << endl;
    }
  }
  return 0;
}