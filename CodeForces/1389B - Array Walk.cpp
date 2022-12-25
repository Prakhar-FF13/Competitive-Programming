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

int dp[int(1e5) + 5][6];
int n, K, Z;

int s(int k, int z, vector<int> &a)
{
  int pos = k - 2 * z;
  if (k == K)
    return a[pos];
  if (pos < 0 || pos >= n)
    return -1e9;
  if (dp[k][z] != -1)
    return dp[k][z];
  int ans = -1e9;
  if (pos - 1 >= 0 && z < Z)
    ans = max(ans, s(k + 1, z + 1, a));
  if (pos + 1 < n)
    ans = max(ans, s(k + 1, z, a));
  return dp[k][z] = ans + a[pos];
}

int main()
{
  RW()
  tt()
  {
    cin >> n >> K >> Z;
    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    ms(dp, -1, sizeof(dp));
    cout << s(0, 0, arr) << endl;
  }
}