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

int main()
{
  RW();
  tt()
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int maxPeaks = 0;
    rep(i, 1, k - 1) if (a[i] > a[i - 1] && a[i] > a[i + 1]) maxPeaks++;
    int i = 0, j = k, ans = maxPeaks, l = 0, r = k - 1;
    while (j < n)
    {
      i++;
      if (i != 0 && a[i] > a[i - 1] && a[i] > a[i + 1])
        maxPeaks--;
      if (a[j - 1] > a[j - 2] && a[j - 1] > a[j])
        maxPeaks++;
      if (maxPeaks > ans)
      {
        ans = maxPeaks;
        l = i;
        r = j;
      }
      j++;
    }
    cout << ans + 1 << " " << l + 1 << endl;
  }
  return 0;
}