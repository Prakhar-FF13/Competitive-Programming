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

vector<deque<int> > subs;

int main()
{
  RW();
  fsi;
  cin >> n;
  vi arr;
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    arr.pb(x);
  }
  for (int i = 0; i < n; i++)
  {
    int x = arr[i];
    int low = 0, high = subs.size() - 1;
    int ans = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (subs[mid].back() <= x)
      {
        ans = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
    }
    if (ans == -1)
    {
      deque<int> y;
      y.pb(x);
      subs.pb(y);
    }
    else
      subs[ans].pb(x);
  }
  for (int i = 0; i < subs.size(); i++)
  {
    for (auto x : subs[i])
    {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}