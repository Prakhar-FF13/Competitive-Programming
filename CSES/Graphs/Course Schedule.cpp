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

int n, m;
vi g[int(1e5) + 5];
vi visited;
vi topOrder;
vi inStack;
bool pos = true;

void dfs(int x)
{
  visited[x] = 1;
  inStack[x] = 1;
  rep(i, 0, g[x].size())
  {
    int v = g[x][i];
    if (!visited[v])
      dfs(v);
    else if (inStack[v] == 1)
      pos = false;
  }
  topOrder.pb(x);
  inStack[x] = 0;
}

int main()
{
  // RW();
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
  }
  visited.assign(n + 3, 0);
  inStack.assign(n + 3, 0);
  pos = true;
  rep(i, 1, n + 1) if (!visited[i])
      dfs(i);

  if (pos == false)
  {
    cout << "IMPOSSIBLE";
    return 0;
  }
  reverse(all(topOrder));
  rep(i, 0, topOrder.size())
          cout
      << topOrder[i] << " ";
  return 0;
}