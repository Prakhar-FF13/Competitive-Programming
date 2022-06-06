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
vi z;

void computeZ(string x)
{
  int n = x.length();
  z.assign(n, 0);
  // left and right index of boundary.
  int l = 0, r = 0;
  rep(i, 1, n)
  {
    // can start with 0 or if in boundary can start with a higher number.
    // boundary condition, highest value cannot be larger than boundary hence minimum.
    if (i <= r)
      z[i] = min(r - i + 1, z[i - l]);
    // now we try to extend the matching, uptil z[i]-1 we matched from start
    // so now we check if z[i] and z[i] + i mathces or not.
    // z[i] will denote prefix index, z[i] + i will denote corresponding substring index.
    while (z[i] + i < n && x[z[i]] == x[i + z[i]])
      z[i]++;
    // new boundary bound is bigger so we change the boundary.
    if (z[i] + i - 1 > r)
      l = i, r = i + z[i] - 1;
  }
}

int main()
{
  // RW();
  fsi;
  cin >> str;
  computeZ(str);
  rep(i, 0, z.size()) if (z[i] + i == str.length())
          cout
      << i << " ";
  cout << str.length();
  return 0;
}