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
vii intervals;
bool cmp(pii x, pii y)
{
  if (x.second == y.second)
    return x.first < y.first;
  return x.second < y.second;
}
int main()
{
  // RW();
  fsi;
  cin >> n >> k;
  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    intervals.pb(mp(x, y));
  }
  sort(all(intervals), cmp);
  int ans = 0;
  set<pii> members;
  rep(i, 0, k)
      members.insert(mp(0, i));
  rep(i, 0, n)
  {
    auto x = members.lower_bound(mp(-1 * intervals[i].first, -1));
    if (x != members.end())
    {
      ans++;
      members.erase(x);
      members.insert(mp(-1 * intervals[i].second, i));
    }
  }
  cout << ans;
  return 0;
}