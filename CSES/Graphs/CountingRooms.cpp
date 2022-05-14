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

int n, m;
string arr[1001];
bool visited[1001][1001];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void floodfill(int x, int y)
{
  visited[x][y] = true;
  rep(i, 0, 4)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] == '.' && visited[nx][ny] == false)
      floodfill(nx, ny);
  }
}

int main()
{
  cin >> n >> m;
  rep(i, 0, n)
  {
    cin >> arr[i];
  }
  rep(i, 0, n)
      rep(j, 0, m)
          visited[i][j] = false;

  int count = 0;
  rep(i, 0, n)
      rep(j, 0, m) if (visited[i][j] == false && arr[i][j] == '.')
  {
    count++;
    floodfill(i, j);
  }

  cout << count << endl;
}