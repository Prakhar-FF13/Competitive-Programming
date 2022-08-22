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

ll powI(ll b, ll c)
{
  if (c == 0)
    return 1;
  ll res = 1;
  while (c > 0)
  {
    if (c & 1)
      res = (res * b) % MOD;
    b = (b * b) % MOD;
    c = c >> 1;
  }
  return res % MOD;
}

ll prod[int(1e6) + 1];
ll invMod[int(1e6) + 1];

void preCompute()
{
  prod[0] = 1;
  prod[1] = 1;
  invMod[1] = 1;
  invMod[0] = 1;
  rep(i, 2, int(1e6) + 1)
  {
    prod[i] = (i * prod[i - 1]) % MOD;
    invMod[i] = powI(prod[i], MOD - 2);
  }
}

int main()
{
  // RW();
  fsi;
  preCompute();
  int n;
  cin >> n;
  while (n--)
  {
    int a, b;
    cin >> a >> b;
    printf("%lld\n", ((prod[a] * invMod[b]) % MOD * invMod[a - b]) % MOD);
  }
  return 0;
}