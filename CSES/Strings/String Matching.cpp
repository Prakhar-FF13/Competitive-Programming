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

string a, b;
vi reset;

void kmpPreprocess(string x)
{
  int n = x.length();
  reset.assign(n, 0);
  reset[0] = 0;
  int i = 1, j = 0;
  while (i < n)
  {
    while (j > 0 && x[i] != x[j])
      j = reset[j - 1];
    reset[i++] = ++j;
  }
}

void match(string x, string y)
{
  int n = x.length(), m = y.length();
  int i = 0, j = 0;
  int cnt = 0;
  while (i < n)
  {
    while (i < n && j < m && x[i] == y[j])
      i++, j++;
    if (j == m)
    {
      cnt++;
      j = reset[j - 1];
      continue;
    }
    if (j != 0)
      j = reset[j - 1];
    else
      i += 1;
  }
  cout << cnt;
}

int main()
{
  // RW();
  cin >> a >> b;
  kmpPreprocess(b);
  // rep(i, 0, b.length())
  //         cout
  //     << reset[i] << " ";
  // cout << endl;
  match(a, b);
  return 0;
}