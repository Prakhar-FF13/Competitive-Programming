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

int indexOfMaxElement(int a[], int n)
{
  int ans = -1e9, id = -1;
  rep(i, 0, n) if (a[i] > ans)
      ans = a[i],
      id = i;

  return id;
}

int main()
{
  RW();
  fsi;
  tt()
  {
    int n;
    cin >> n;
    int a[n], b[n];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    int maxA = indexOfMaxElement(a, n), maxB = indexOfMaxElement(b, n);
    if (a[maxA] > b[maxB])
    {
      rep(i, 0, n) if (i != maxA && b[i] > a[i])
          swap(a[i], b[i]);
    }
    else
    {
      rep(i, 0, n) if (i != maxB && a[i] > b[i])
          swap(a[i], b[i]);
    }
    maxA = indexOfMaxElement(a, n), maxB = indexOfMaxElement(b, n);
    cout << a[maxA] * b[maxB] << endl;
  }
  return 0;
}