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
  vii p;
  int n, k;
  cin >> n >> k;
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      int cnt = 0;
      while (n % i == 0)
      {
        n = n / i;
        cnt++;
      }
      p.pb(mp(i, cnt));
    }
  }
  if (n > 1)
    p.pb(mp(n, 1));
  int pSum = 0;
  rep(i, 0, p.size()) pSum += p[i].second;
  if (k > pSum)
    cout << -1;
  else
  {
    int remaining = 1;
    rep(i, 0, p.size())
    {
      if (k - 1 > 0)
      {
        while (p[i].second > 0 && k > 1)
        {
          k--;
          p[i].second--;
          cout << p[i].first << " ";
        }
        if (p[i].second > 0)
        {
          remaining *= pow(p[i].first, p[i].second);
          p[i].second = 0;
        }
      }
      else
      {
        remaining *= pow(p[i].first, p[i].second);
      }
    }
    cout << remaining;
  }
  return 0;
}