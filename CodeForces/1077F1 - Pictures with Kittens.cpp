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

int n, k, X;
vector<int> arr;
ll dp[201][201][201];

ll s(int ind, int prevTaken, int x)
{
  if (x == 0 && prevTaken + k - 1 < n)
  {
    return -1e15;
  }
  if (ind > n)
  {
    return x == 0 ? 0 : ll(-1e15);
  }
  if (dp[ind][prevTaken][x] != -1)
    return dp[ind][prevTaken][x];
  if (ind <= prevTaken + k - 1)
    return dp[ind][prevTaken][x] = max(s(ind + 1, prevTaken, x), (x > 0 ? (s(ind + 1, ind, x - 1) + arr[ind - 1]) : ll(-1e15)));
  else
  {
    if (x > 0)
      return dp[ind][prevTaken][x] = s(ind + 1, ind, x - 1) + arr[ind - 1];
    else
      return dp[ind][prevTaken][x] = ll(-1e15);
  }
}

int main()
{
  RW();
  cin >> n >> k >> X;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    arr.pb(x);
  }
  ms(dp, -1, sizeof(dp));
  ll ans = s(1, 0, X);
  cout << (ans < 0 ? -1 : ans);
  return 0;
}