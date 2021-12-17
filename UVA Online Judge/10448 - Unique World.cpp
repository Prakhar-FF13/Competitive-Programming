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

unordered_map<int, vii> g;
int n, m;
int costMat[52][52];
vector<int> parent;
vector<int> costToTarget;

void bfs(int s, int t)
{
  queue<int> q;
  parent.clear();
  costToTarget.clear();
  parent.assign(n + 1, -1);
  vi visited;
  visited.assign(n + 1, 0);
  q.push(s);
  while (!q.empty())
  {
    int top = q.front();
    q.pop();
    visited[top] = 1;
    for (int i = 0; i < g[top].size(); i++)
    {
      pii neigh = g[top][i];
      if (visited[neigh.first] == 0)
      {
        parent[neigh.first] = top;
        q.push(neigh.first);
      }
      if (neigh.first == t)
        break;
    }
  }
  while (parent[t] != -1)
  {
    costToTarget.pb(costMat[t][parent[t]]);
    t = parent[t];
  }
}

ll ccDp[1000001][52];

ll coinChangeEvenTimes(int idx, int w)
{
  if (w == 0)
    return 0;
  if (w < 0 || idx >= costToTarget.size())
    return 1e9;
  if (ccDp[w][idx] != 1e9)
    return ccDp[w][idx];

  ll ans = 1e9;
  for (int i = 0; costToTarget[idx] * i <= w; i += 2)
  {
    ans = min(coinChangeEvenTimes(idx + 1, w - (costToTarget[idx] * i)) + i, ans);
  }

  return ccDp[w][idx] = ans;
}

int main()
{
  int N;
  cin >> N;
  while (N--)
  {
    cin >> n >> m;
    g.clear();
    ms(costMat, (int)1e9, sizeof(costMat));
    rep(i, 0, m)
    {
      int id1, id2, c;
      cin >> id1 >> id2 >> c;
      g[id1].pb(mp(id2, c));
      g[id2].pb(mp(id1, c));
      costMat[id1][id2] = c;
      costMat[id2][id1] = c;
    }
    int k;
    cin >> k;
    while (k--)
    {
      int id1, id2, reqC;
      cin >> id1 >> id2 >> reqC;
      bfs(id1, id2);
      // rep(i, 0, costToTarget.size())
      // {
      //   cout << costToTarget[i] << " ";
      // }
      // cout << endl;
      int cost = 0;
      cost = accumulate(all(costToTarget), cost);
      if (reqC < cost)
      {
        cout << "No\n";
      }
      else if (reqC == cost)
      {
        cout << "Yes " << costToTarget.size() << endl;
      }
      else
      {
        rep(x, 0, 1000001)
            rep(idx, 0, 52)
                ccDp[x][idx] = 1e9;
        int times = coinChangeEvenTimes(1, reqC - cost);
        if (times == 1e9)
          cout << "No\n";
        else
        {
          times = times + costToTarget.size();
          cout << "Yes " << times << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}