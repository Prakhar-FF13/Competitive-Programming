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

int n, k;
vi arr;

bool possible(ll sum)
{
  int req = 0;
  ll s = 0;
  int i = 0;
  while (i < n)
  {
    if (s + arr[i] <= sum)
      s += arr[i++];
    else
    {
      s = 0;
      req++;
    }
  }
  return (req + 1 <= k);
}

int main()
{
  // RW();
  cin >> n >> k;
  ll l = 0, h = 1e15;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    arr.pb(x);
    l = max(l, x * 1LL);
  }

  ll ans = 1e18;
  while (l <= h)
  {
    ll mid = l + (h - l) / 2;
    if (possible(mid))
    {
      ans = mid;
      h = mid - 1;
    }
    else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}