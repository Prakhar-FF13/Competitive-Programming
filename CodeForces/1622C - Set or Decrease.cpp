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

ll accurateFloor(ll a, ll b)
{
  ll x = a / b;
  if (x * b > a)
    x--;
  return x;
}

int main()
{
  RW();
  tt()
  {
    ll n, k;
    cin >> n >> k;
    ll P[n], A[n];
    rep(i, 0, n) cin >> A[i];
    sort(A, A + n);
    P[0] = A[0];
    rep(i, 1, n) P[i] = P[i - 1] + A[i];
    if (P[n - 1] <= k)
      cout << 0 << endl;
    else
    {
      ll ans = 1e18;
      rep(z, 0, n)
      {
        ll y = P[0] - accurateFloor(k - P[n - 1 - z] + P[0], z + 1);
        ans = min(ans, z + max(0LL, y));
      }
      cout << ans << endl;
    }
  }
  return 0;
}