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

ll power(ll a, ll b)
{
  if (b == 0)
    return a;
  ll res = power(a, b / 2);
  res *= res;
  if (b & 1)
    res *= a;
  return res;
}

int main()
{
  RW();
  tt()
  {
    ll a, b, n;
    cin >> n >> a >> b;
    if (a == 1)
    {
      if ((n - 1) % b == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    else
    {
      ll x = 1;
      bool p = false;
      while (x <= n)
      {
        if ((n - x) % b == 0)
        {
          p = true;
          break;
        }
        x *= a;
      }
      if (p)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}