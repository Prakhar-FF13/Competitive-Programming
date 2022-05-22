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

int n;
int parent[2 * int(1e5) + 5];
vi visited;
vi depth;
int steps;
deque<int> path;

void dfs(int x)
{
  visited[x] = 1;
  path.pb(x);
  if (!visited[parent[x]])
    dfs(parent[x]);
  else
    steps += depth[parent[x]];
  steps++;
}

int main()
{
  // RW();
  cin >> n;
  rep(i, 1, n + 1) cin >> parent[i];
  depth.assign(n + 3, 0);
  visited.assign(n + 3, 0);
  rep(i, 1, n + 1)
  {
    if (!visited[i])
    {
      steps = 0;
      dfs(i);
      bool cyclePart = false;
      while (!path.empty())
      {
        int x = path.front();
        if (parent[path.back()] == x)
          cyclePart = true;
        path.pop_front();
        depth[x] = steps;
        if (!cyclePart)
          steps--;
      }
    }
  }

  rep(i, 1, n + 1)
          cout
      << depth[i] << " ";
  return 0;
}