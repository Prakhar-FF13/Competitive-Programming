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
#define NINF -ll(1e18)
#define INF ll(1e18)

int n, m, k, q;
int parent[2 * int(1e5) + 5][32];

int main()
{
  // RW();
  fsi;
  cin >> n >> q;
  rep(i, 0, n + 1) rep(j, 0, 32) parent[i][j] = -1;
  rep(i, 1, n + 1) cin >> parent[i][0];
  rep(j, 1, 32)
      rep(i, 1, n + 1)
          parent[i][j] = parent[parent[i][j - 1]][j - 1];
  rep(i, 0, q)
  {
    int x, k;
    cin >> x >> k;
    if (k > 0)
      for (int j = 31; j >= 0; j--)
      {
        if (((k >> j) & 1))
        {
          x = parent[x][j];
        }
      }
    cout << x << endl;
  }
  return 0;
}