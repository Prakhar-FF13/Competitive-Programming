#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
  while (t--)
#define pb push_back
#define mp make_pair
#define ms memset
#define all(v) v.begin(), v.end()
#define pob pop_back

int n;
vector<int> arr;
int dp[20][1 << 18];
int countP[20][1 << 18];

int s(int prev, int mask)
{
  if (dp[prev][mask] != -1)
    return dp[prev][mask];
  for (int j = 1; j < arr.size(); j++)
  {
    if ((mask & (1 << j)) == 0)
    {
      if ((mask | (1 << j)) == ((1 << arr.size()) - 1))
      {
        dp[prev][mask] = abs(arr[j] - arr[prev]) + arr[j];
        countP[prev][mask] += 1;
        return dp[prev][mask];
      }
      else
      {
        int x = s(j, mask | (1 << j));
        if (x + abs(arr[j] - arr[prev]) == dp[prev][mask])
        {
          countP[prev][mask] += countP[j][mask | (1 << j)];
        }
        else if (x + abs(arr[j] - arr[prev]) > dp[prev][mask])
        {
          dp[prev][mask] = x + abs(arr[j] - arr[prev]);
          countP[prev][mask] = countP[j][mask | (1 << j)];
        }
      }
    }
  }
  return dp[prev][mask];
}

int main()
{
  while (1)
  {
    cin >> n;
    arr.clear();
    arr.pb(0);
    if (n == 0)
      break;
    rep(i, 0, n)
    {
      int x;
      cin >> x;
      arr.pb(x);
    }
    ms(dp, -1, sizeof(dp));
    ms(countP, 0, sizeof(countP));
    cout << s(0, 1) + 2 * n;
    cout << " " << countP[0][1] << endl;
  }
  return 0;
}