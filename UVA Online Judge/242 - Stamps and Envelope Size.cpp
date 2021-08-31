/*
  very Good Coin Change DP.
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
#define pob pop_back

int s, n, maxVal;
vector<int> coins;
int dp[1200][15];

bool canBeMade(int idx, int value, int k)
{
  if (value == 0)
    return true;
  if (k == 0 || value < 0 || idx == coins.size())
    return false;

  if (dp[value][k] != -1)
    return dp[value][k];

  dp[value][k] = canBeMade(idx + 1, value, k) ||
                 canBeMade(idx + 1, value - coins[idx], k - 1) ||
                 canBeMade(idx, value - coins[idx], k - 1);
  if (dp[value][k] == true)
  {
    rep(i, k, s + 1)
        dp[value][i] = true;
  }

  return dp[value][k];
}

void solve(int value)
{
  ms(dp, -1, sizeof(dp));
  maxVal = 0;
  while (1)
  {
    if (canBeMade(0, value, s) == 1)
      maxVal = value;
    else
      break;
    value++;
  }
}

int main()
{
  RW()
  fsi;
  while (cin >> s, s)
  {
    cin >> n;
    int maximum = -1;
    vi ans;
    rep(i, 0, n)
    {
      int x;
      cin >> x;

      coins.clear();
      coins.assign(x, 0);

      rep(j, 0, x) cin >> coins[j];

      solve(1);

      if (maxVal == maximum)
      {
        if (coins.size() < ans.size())
          ans = coins;
        else if (coins.size() == ans.size())
        {
          for (int i = coins.size() - 1; i >= 0; i--)
          {
            if (coins[i] < ans[i])
            {
              ans = coins;
              break;
            }
            else if (ans[i] < coins[i])
              break;
          }
        }
      }
      else if (maxVal > maximum)
      {
        maximum = maxVal;
        ans = coins;
      }
    }
    printf("max coverage =%4d :", maximum);
    rep(i, 0, ans.size())
        printf("%3d", ans[i]);
    cout << endl;
  }
  return 0;
}