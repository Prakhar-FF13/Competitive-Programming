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
#define LSOne(x) x & (-x)
#define pob pop_back

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int,int> > b)
{
  pii x = a.second;
  pii y = b.second;
  if (x.first == y.first)
    return x.second > y.second;
  return x.first < y.first;
}

int main()
{
  int n;
  cin>>n;
  vector<pair<int, pair<int, int> > >arr(n);
  for(int i =0 ; i < n; i++) {
    int x, y;
    cin>>x>>y;
    arr[i] = mp(i, mp(x, y));
  }
  sort(all(arr), cmp);
  int maxR = -1;
  int contained[n], contains[n];
  for(int i = 0; i < arr.size(); i++) {
    pair<int, pii > p = arr[i];
    pii y = p.second;
    if (maxR >= y.second) contained[p.first] = 1;
    else                  contained[p.first] = 0;
    maxR = max(maxR, y.second);
  }
  int minL = 1e9+7;
  for(int i = arr.size() - 1; i >= 0; i--) {
    pair<int, pii > p = arr[i];
    pii y = p.second;
    if (y.second >= minL) contains[p.first] = 1;
    else                  contains[p.first] = 0;
    minL = min(minL, y.second);
  }
  for(int i =0 ; i < n; i++)
    cout<<contains[i]<<" ";
  cout<<endl;
  for(int i =0 ; i < n; i++)
    cout<<contained[i]<<" ";
  return 0;
}