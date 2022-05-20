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

int n, m, q;
vi parent, depth, cycleId;
vi g[2 * int(1e5) + 5];
int binLift[2 * int(1e5) + 5][22];
vector<map<int, int> > allCycles;

int main()
{
  RW();
  // fsi;
  cin >> n >> q;
  parent.assign(n + 3, -1);
  depth.assign(n + 3, -1);
  rep(i, 1, n + 1)
  {
    cin >> parent[i];
    g[parent[i]].pb(i);
  }
  // find cycle.
  // -2 => not processed this node.
  // -1 => part of tree, should check root.
  // >=0 => cycle index.
  cycleId.assign(n + 3, -2);
  rep(i, 1, n + 1)
  {
    if (cycleId[i] != -2)
      continue;

    // get all nodes reachable from this.
    int x = i;
    vi path;
    while (cycleId[x] == -2)
    {
      path.pb(x);
      // just a dummy denoting we are processing it, cannot leave it at 2.
      // if we leave it at -2 then if it is part of cycle we will keep looping here.
      cycleId[x] = -3;
      x = parent[x];
    }

    // last node's parent will be first node in the path;
    map<int, int> indexOfNodeInCycle;
    bool cycleNode = false;
    int lastNode = path[path.size() - 1];
    int k = 0;
    rep(i, 0, path.size())
    {
      int v = path[i];
      cycleNode = cycleNode || parent[lastNode] == v;
      if (cycleNode)
        indexOfNodeInCycle[v] = k++;
      cycleId[v] = cycleNode ? allCycles.size() : -1;
    }
    allCycles.pb(indexOfNodeInCycle);
  }

  // nodes which are part of cycle are identified.
  // now we to get the distance from cycle nodes to tree nodes.
  // i.e distance of nodes to cycle.
  rep(i, 1, n + 1)
  {
    // node is part of cycle if cycleId >= 0
    // node is in tree if -1;
    // we will traverse in revese graph.
    if (cycleId[i] == -1 || depth[i] != -1)
      continue;

    depth[i] = 0;
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
      int u = q.front();
      q.pop();

      rep(j, 0, g[u].size())
      {
        int v = g[u][j];
        if (cycleId[v] != -1 || depth[v] != -1)
          continue;

        depth[v] = depth[u] + 1;
        q.push(v);
      }
    }
  }

  // binary lift on nodes.
  rep(i, 0, n + 1) rep(j, 0, 22) binLift[i][j] = -1;
  rep(i, 1, n + 1) binLift[i][0] = parent[i];
  rep(j, 1, 22)
      rep(i, 1, n + 1)
          binLift[i][j] = binLift[binLift[i][j - 1]][j - 1];

  vi ans;
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    // cycleIds of cycles to which these two nodes belong.
    int ca = cycleId[binLift[a][21]], cb = cycleId[binLift[b][21]];
    // both belong to different cycle => different component.
    if (ca != cb)
    {
      ans.pb(-1);
      continue;
    }
    // one belongs to cycle.
    if (cycleId[a] != -1 || cycleId[b] != -1)
    {
      // v belongs to tree but u belongs to cycle.
      if (cycleId[a] != -1 && cycleId[b] == -1)
      {
        ans.pb(-1);
        continue;
      }
      int distanceToCycle = depth[a];
      int ra = a;
      // get root of the tree to which u belongs.
      rep(j, 0, 22) if (((depth[a] >> j) & 1)) ra = binLift[ra][j];

      // get the cycle of ra and b;
      map<int, int> abCycle = allCycles[cycleId[ra]];

      // get indices of both ra and b
      int ira = abCycle[ra], ib = abCycle[b];
      int diff = ira <= ib ? ib - ira : abCycle.size() - (ira - ib);
      ans.pb(distanceToCycle + diff);
    }
    else // both belong to tree.
    {
      if (depth[b] > depth[a])
      {
        ans.pb(-1);
        continue;
      }
      int depthDiff = depth[a] - depth[b];
      int reachB = a;
      rep(j, 0, 22) if (((depthDiff >> j) & 1)) reachB = binLift[reachB][j];
      ans.pb(reachB == b ? depthDiff : -1);
    }
  }
  rep(i, 0, ans.size())
    cout<<ans[i]<<"\n";
  return 0;
}