/*
  Tags - DP Knapsack like. Very good problem.
*/

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

int n, f;
int arr[50];
map<pair<int, int>, string> x;

string solve(int ind, int w, string tmp)
{
  if (ind == n)
  {
    if (w == f)
      return tmp;
    else
      return "";
  }
  else if (x.find(mp(ind, w)) != x.end())
  {
    string p = x[mp(ind, w)];
    rep(i, 0, min(tmp.length(), p.length())) if (p[i] != tmp[i])
        p[i] = '?';

    return x[mp(ind, w)] = p;
  }
  else
  {
    string p = solve(ind + 1, w + arr[ind], tmp + "+");
    string q = solve(ind + 1, w - arr[ind], tmp + "-");

    if (p == "" && q == "")
      return x[mp(ind, w)] = "";
    if (p == "")
      return x[mp(ind, w)] = q;
    if (q == "")
      return x[mp(ind, w)] = p;

    rep(i, 0, n) if (p[i] != q[i])
        p[i] = '?';

    return x[mp(ind, w)] = p;
  }
}

int main()
{
  RW()
  fsi;
  while (cin >> n >> f, n)
  {
    x.clear();
    rep(i, 0, n)
    {
      cin >> arr[i];
    }

    string ans = solve(0, 0, "");

    cout << (ans == "" ? "*" : ans) << endl;
  }
  return 0;
}