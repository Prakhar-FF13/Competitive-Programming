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

int n, m;
vi g[int(1e5) + 5];
vi visited;
vi color;
bool possible = true;

void colorG(int x)
{
  visited[x] = 1;
  queue<int> q;
  color[x] = 1;
  q.push(x);
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    rep(i, 0, g[x].size())
    {
      if (!visited[g[x][i]])
      {
        visited[g[x][i]] = 1;
        q.push(g[x][i]);
        color[g[x][i]] = color[x] == 1 ? 2 : 1;
      }
      else if (color[g[x][i]] == color[x])
      {
        possible = false;
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  visited.assign(n + 3, 0);
  color.assign(n + 3, -1);
  rep(i, 1, n + 1) if (visited[i] == 0)
      colorG(i);
  if (!possible)
  {
    cout << "IMPOSSIBLE";
    return 0;
  }
  rep(i, 1, n + 1)
          cout
      << color[i] << " ";
  return 0;
}