/*
  Very Good DP Question. Interval DP Must solve.
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

int n, k;
ll dp[201][201][31];

void print(int L, int R, int K)
{
  if (K == 1)
  {
    if (R - L + 1 == 1)
    {
      cout << "Depot " << K
           << " at restaurant " << R + 1 << " serves restaurant "
           << R + 1 << endl;
    }
    else
    {
      cout << "Depot " << K
           << " at restaurant " << ((R + L) / 2) + 1 << " serves restaurants "
           << L + 1 << " to " << R + 1 << endl;
    }
  }
  else
  {
    rep(x, L, R)
    {
      if (dp[L][R][K] == dp[L][x][K - 1] + dp[x + 1][R][1])
      {
        print(L, x, K - 1);
        if (R - x == 1)
        {
          cout << "Depot " << K
               << " at restaurant " << R + 1 << " serves restaurant "
               << R + 1 << endl;
        }
        else
        {
          cout << "Depot " << K
               << " at restaurant " << ((R + x + 1) / 2) + 1 << " serves restaurants "
               << x + 2 << " to " << R + 1 << endl;
        }
        return;
      }
    }
  }
}

int main()
{
  RW();
  fsi;
  int xt = 1;
  while (cin >> n >> k, n)
  {
    int a[n];
    rep(i, 0, n)
    {
      cin >> a[i];
    }
    if (k == n)
    {
      cout << "Chain " << xt++ << endl;
      rep(i, 0, n)
      {
        cout << "Depot " << i + 1
             << " at restaurant " << i + 1 << " serves restaurant "
             << i + 1 << endl;
      }
      cout << "Total distance sum = " << 0 << endl;
    }
    else
    {
      rep(i, 0, 201) rep(j, 0, 201) rep(K, 0, 31) dp[i][j][K] = 10000000;
      rep(i, 0, n)
          dp[i][i][0] = dp[i][i][1] = 0;
      rep(i, 0, n)
      {
        rep(j, i + 1, n)
        {
          int mid = a[(j + i) / 2];
          dp[i][j][1] = 0;
          rep(x, i, j + 1)
              dp[i][j][1] += abs(a[x] - mid);
        }
      }
      rep(K, 2, k + 1)
      {
        rep(i, 0, n)
        {
          rep(j, i + 1, n)
          {
            rep(x, i, j)
            {
              dp[i][j][K] = min(dp[i][j][K], dp[i][x][K - 1] + dp[x + 1][j][1]);
            }
          }
        }
      }
      cout << "Chain " << xt++ << endl;
      print(0, n - 1, k);
      cout << "Total distance sum = " << dp[0][n - 1][k] << endl;
    }
    cout << endl;
  }
  return 0;
}