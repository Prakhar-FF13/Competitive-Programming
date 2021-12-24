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

#define inf (int)1e9

int costMat[52][52];
int floydCost[52][52];
int pathMat[52][52];
int dp[52][100001];
int n, m, k, N;
vector<int> costToTarget;

void initialize()
{
  rep(i, 0, 52)
  {
    rep(j, 0, 52)
    {
      costMat[i][j] = inf;
      floydCost[i][j] = inf;
      pathMat[i][j] = inf;
    }
    costMat[i][i] = 0;
    floydCost[i][i] = 0;
    pathMat[i][i] = i;
  }
}

void floydWarshall()
{
  rep(k, 1, n + 1)
  {
    rep(i, 1, n + 1)
    {
      rep(j, 1, n + 1)
      {
        if (floydCost[i][k] == inf || floydCost[k][j] == inf)
        {
          continue;
        }
        if (floydCost[i][k] + floydCost[k][j] < floydCost[i][j])
        {
          floydCost[i][j] = floydCost[i][k] + floydCost[k][j];
          pathMat[i][j] = pathMat[i][k];
        }
      }
    }
  }
}

vector<int> getNodesInPath(int s, int t)
{
  vector<int> path;
  if (pathMat[s][t] == inf)
    return path;

  path.pb(s);
  while (s != t)
  {
    s = pathMat[s][t];
    path.pb(s);
  }

  return path;
}

vector<int> getCostInPath(vector<int> &x)
{
  vector<int> cost;
  for (int i = x.size() - 2; i >= 0; i--)
  {
    cost.pb(costMat[x[i]][x[i + 1]]);
  }
  return cost;
}

int coinChange(int idx, int w)
{
  if (idx >= costToTarget.size() || w < 0)
  {
    return inf + 1;
  }
  if (w == 0)
  {
    return 0;
  }
  if (dp[idx][w] != inf)
  {
    return dp[idx][w];
  }

  return dp[idx][w] = min(coinChange(idx, w - costToTarget[idx]) + 1,
                          min(coinChange(idx + 1, w - costToTarget[idx]) + 1,
                              coinChange(idx + 1, w)));
}

int main()
{
  cin >> N;
  while (N--)
  {
    cin >> n >> m;
    initialize();
    rep(i, 0, m)
    {
      int id1, id2, c;
      cin >> id1 >> id2 >> c;
      costMat[id1][id2] = c;
      costMat[id2][id1] = c;
      pathMat[id1][id2] = id2;
      pathMat[id2][id1] = id1;
      floydCost[id1][id2] = 1;
      floydCost[id2][id1] = 1;
    }
    floydWarshall();
    cin >> k;
    rep(pqr, 0, k)
    {
      int id1, id2, c;
      cin >> id1 >> id2 >> c;
      costToTarget = getNodesInPath(id1, id2);
      if (costToTarget.size() == 0)
      {
        cout << "No" << endl;
        continue;
      }
      costToTarget = getCostInPath(costToTarget);
      int sum = 0;
      sum = accumulate(all(costToTarget), sum);
      if (sum > c || ((c - sum) % 2 == 1))
      {
        cout << "No" << endl;
      }
      else if (sum == c)
      {
        cout << "Yes " << costToTarget.size() << endl;
      }
      else
      {
        c -= sum;
        rep(i, 0, n + 1)
        {
          rep(j, 0, (c / 2) + 1)
          {
            dp[i][j] = inf;
          }
        }

        int times = coinChange(1, c / 2);
        if (times >= inf)
        {
          cout << "No" << endl;
        }
        else
        {
          cout << "Yes " << times * 2 + costToTarget.size() << endl;
        }
      }
    }
    cout << endl;
  }
  return 0;
}