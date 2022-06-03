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

string str;
vi border;
void findBorder(string x)
{
  int len = x.length();
  int i = 1, j = 0;
  border[0] = 0;
  while (i < len)
  {
    if (x[i] == x[j])
      border[i++] = ++j;
    else
    {
      if (j > 0)
        j = border[j - 1];
      else
        i++;
    }
  }
}

int main()
{
  // RW();
  fsi;
  cin >> str;
  vi ans;
  border.assign(str.length(), 0);
  findBorder(str);
  int j = border[str.length() - 1];
  while (j > 0)
  {
    ans.pb(j);
    j = border[j - 1];
  }
  reverse(all(ans));
  rep(i, 0, ans.size())
          cout
      << ans[i] << " ";
  return 0;
}