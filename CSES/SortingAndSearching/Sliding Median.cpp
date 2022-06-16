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
vl arr;
int main()
{
  // RW();
  cin >> n >> k;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    arr.pb(x);
  }
  if (k == 1)
  {
    rep(i, 0, n)
            cout
        << arr[i] << " ";
    return 0;
  }
  if (k == 2)
  {
    rep(i, 0, n - 1)
    {
      cout << min(arr[i], arr[i + 1]) << " ";
    }
    return 0;
  }
  vii t;
  set<pii> l, r;
  rep(i, 0, k) t.pb(mp(arr[i], i));
  sort(all(t));
  int mid = k / 2 + k % 2;
  rep(i, 0, mid)
      l.insert(t[i]);
  rep(i, mid, k)
      r.insert(t[i]);

  int reqDiff = r.size() - l.size();
  int i = 0, j = k - 1;
  while (j < n)
  {
    int item = (*l.rbegin()).first;
    cout << item << " ";
    if (l.find(mp(arr[i], i)) != l.end())
      l.erase(l.find(mp(arr[i], i)));
    else
      r.erase(r.find(mp(arr[i], i)));
    j += 1;
    i += 1;
    if (j < n)
    {
      if (arr[j] > (*l.rbegin()).first)
        r.insert(mp(arr[j], j));
      else
        l.insert(mp(arr[j], j));
      int currDiff = r.size() - l.size();
      while (currDiff > reqDiff)
      {
        l.insert(*r.begin());
        int x = r.begin()->first;
        r.erase(r.begin());
        currDiff = r.size() - l.size();
      }
      while (currDiff < reqDiff)
      {
        r.insert(*l.rbegin());
        int x = l.rbegin()->first;
        l.erase(l.find(*l.rbegin()));
        currDiff = r.size() - l.size();
      }
    }
  }
  return 0;
}