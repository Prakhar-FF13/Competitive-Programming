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

ll pow(ll b, ll c, ll mod)
{
  if (c == 0)
    return 1;

  ll res = pow(b, c / 2, mod) % mod;
  res = (res * res) % mod;
  if (c & 1)
    res = (res * b) % mod;

  return res;
}

int main()
{
  // RW();
  int n;
  cin >> n;
  ll numb = 1, sum = 1, prod = 1, d = 1;
  rep(i, 0, n)
  {
    ll p, k;
    cin >> p >> k;
    ll pk = pow(p, k, MOD);
    ll pkprod = pow(p, ((k + 1) * k) / 2, MOD);
    ll invp = pow(p - 1, MOD - 2, MOD);

    numb = (numb * (k + 1)) % MOD;
    sum = (sum * ((pk % MOD * p % MOD) % MOD - 1) % MOD * invp % MOD) % MOD;
    prod = (pow(prod, k + 1, MOD) * pow(pkprod, d, MOD)) % MOD;
    d = (d * (k + 1)) % (MOD - 1);
  }
  cout << numb << " " << sum << " " << prod;
  return 0;
}