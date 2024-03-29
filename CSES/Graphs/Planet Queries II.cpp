#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define endl '\n'

const long long inf = 1LL << 60; // 1.5e18
const int md = 1000000007;

int succ[21][200005];
int vis[200005];
int len[200005];
void dfs(int s)
{
  if (vis[s])
    return;
  vis[s] = 1;
  dfs(succ[0][s]);
  len[s] = len[succ[0][s]] + 1;
}
int lift(int x, int d)
{
  if (d <= 0)
    return x;
  int i = 0;
  while (d > 0)
  {
    if (d & 1)
      x = succ[i][x];
    d >>= 1;
    i++;
  }
  return x;
}
void solve()
{
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> succ[0][i];
  for (int i = 1; i <= 20; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      succ[i][j] = succ[i - 1][succ[i - 1][j]];
    }
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i])
      dfs(i);
  while (q--)
  {
    int x, y;
    cin >> x >> y;
    int xx = lift(x, len[x]);          // end of the cycle (Case: x and y are in cycle such that x appears after y)
    if (lift(x, len[x] - len[y]) == y) // if y is infront of x
      cout << len[x] - len[y] << endl;
    else if (lift(xx, len[xx] - len[y]) == y)
      cout << len[x] + len[xx] - len[y] << endl;
    else
      cout << -1 << endl;
  }
}
signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++)
  {
    solve();
    cout << '\n';
  }
}