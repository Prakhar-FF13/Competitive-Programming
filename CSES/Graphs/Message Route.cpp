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
vi parent;

void bfs(int x)
{
  visited[x] = 1;
  queue<int> q;
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
        parent[g[x][i]] = x;
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  rep(i, 0, m)
  {
    int x, y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }
  visited.assign(n + 3, 0);
  parent.assign(n + 3, -1);

  bfs(1);

  vi comps;

  int x = n;

  if (parent[x] == -1)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  while (parent[x] != -1)
  {
    comps.pb(parent[x]);
    x = parent[x];
  }
  reverse(all(comps));

  cout << comps.size() + 1 << endl;
  rep(i, 0, comps.size())
  {
    cout << comps[i] << " ";
  }
  cout << n << endl;
  return 0;
}