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

int m, n;
unordered_map<string, vector<string> > g;
stack<string> st;
unordered_map<string, int> dfs_num, dfs_low, visited;
int dfsCounter = 1;

void clear()
{
  g.clear();
  dfs_num.clear();
  dfs_low.clear();
  visited.clear();
  while(st.size())
    st.pop();
  dfsCounter = 1;
}

void tarjanSSC(string u)
{
  visited[u] = 1;
  dfs_num[u] = dfs_low[u] = dfsCounter++;
  st.push(u);
  rep(i, 0, g[u].size())
  {
    string v = g[u][i];
    if (dfs_num[v] == 0)
      tarjanSSC(v);
    if (visited[v] == 1)
      dfs_low[u] = min(dfs_low[v], dfs_low[u]);
  }
  if (dfs_low[u] == dfs_num[u])
  {
    while (1)
    {
      string v = st.top();
      st.pop();
      visited[v] = 0;
      cout<<v;
      if (u == v) break;
      cout<<", ";
    }
    cout<<endl;
  }
}

int main()
{
  RW();
  fsi;
  int d = 1;
  while (cin >> n >> m, n)
  {
    clear();
    vector<string> x;
    rep(i, 0, m)
    {
      string a, b;
      cin >> a >> b;
      g[a].pb(b);
      x.pb(a);
      x.pb(b);
    }
    cout << "Calling circles for data set " << d++ << ":" << endl;
    for(string str: x)
      if (dfs_num[str] == 0) {
        tarjanSSC(str);
      }
    cout << endl;
  }
  return 0;
}