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

int n;
vector<ll> arr;

bool possible(ll k)
{
  vector<ll> tmp(n, 0);
  for (int i = n - 1; i >= 2; i--)
  {
    tmp[i] += arr[i];
    ll rem = tmp[i] - arr[i] >= k ? arr[i] : arr[i] - (k - (tmp[i] - arr[i]));
    if (rem <= 0)
      continue;
    tmp[i - 1] += rem / 3;
    tmp[i - 2] += 2 * (rem / 3);
    tmp[i] -= 3 * (rem / 3);
  }
  tmp[0] += arr[0];
  tmp[1] += arr[1];
  rep(i, 0, n) if (tmp[i] < k) return false;
  return true;
}

int main()
{
  RW();
  tt()
  {
    cin >> n;
    arr.clear();
    ll high = 0;
    rep(i, 0, n)
    {
      int x;
      cin >> x;
      arr.pb(x);
      high += x;
    }
    ll low = 0, ans = -1;
    while (low <= high)
    {
      ll mid = low + (high - low) / 2;
      if (possible(mid))
      {
        ans = max(ans, mid);
        low = mid + 1;
      }
      else
        high = mid - 1;
    }

    cout << ans << endl;
  }
  return 0;
}