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

int main()
{
  RW();
  fsi;
  tt()
  {
    int n;
    cin >> n;
    vector<int> arr(n), sarr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
      sarr[i] = arr[i];
    }
    sort(all(sarr));
    int notEqualElem = -1, notEqualStart = -1;
    rep(i, 0, n) if (sarr[i] != arr[i])
    {
      notEqualElem = sarr[i];
      notEqualStart = i;
      break;
    }
    if (notEqualElem == -1)
    {
      rep(i, 0, n)
              cout
          << arr[i] << " ";
      cout << endl;
    }
    else
    {
      int idx = -1;
      rep(i, 0, n)
      {
        if (arr[i] == notEqualElem)
        {
          idx = i;
          break;
        }
      }
      reverse(arr.begin() + notEqualStart, arr.begin() + idx + 1);

      for (int i = 0; i < n; i++)
      {
        cout << arr[i] << " ";
      }
      cout << endl;
    }
  }
}