/*
  Two pointer Problem Greedy . Must Solve problem. Extremely Good.
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
ll n, k;
vl a, sa;

bool check(ll x, ll y)
{
  vi b;
  int n = a.size();
  rep(i, 0, a.size())
  {
    b.pb((a[i] >= x && a[i] <= y) ? 1 : -1);
    if (i > 0)
      b[i] += b[i - 1];
  }
  if (b[n - 1] < k)
    return false;
  else
    return true;
}

int main()
{
  RW();
  fsi;
  tt()
  {
    cin >> n >> k;
    a.clear();
    sa.clear();
    rep(i, 0, n)
    {
      int x;
      cin >> x;
      a.pb(x);
      sa.pb(x);
    }
    sort(all(sa));
    int i = 0, j = 0, ansI = -1, ansJ = -1, ansLen = 1e9;
    while (j < n && i < n)
    {
      if (check(sa[i], sa[j]))
      {
        if (sa[j] - sa[i] + 1 < ansLen)
        {
          ansLen = sa[j] - sa[i] + 1;
          ansI = sa[i], ansJ = sa[j];
        }
        i++;
      }
      else
      {
        j++;
      }
    }
    if (ansI == -1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << ansI << " " << ansJ << endl;
      vi b;
      int n = a.size();
      rep(i, 0, a.size())
      {
        b.pb(a[i] >= ansI && a[i] <= ansJ ? 1 : -1);
        if (i > 0)
          b[i] += b[i - 1];
      }
      int prev = 0;
      int subs = 1;
      int i = 0;
      while (i < n)
      {
        if (b[i] == subs && subs != k)
        {
          cout << prev + 1 << " " << i + 1 << endl;
          subs++;
          prev = i + 1;
        }
        i++;
      }
      cout << prev + 1 << " " << n << endl;
    }
  }
  return 0;
}