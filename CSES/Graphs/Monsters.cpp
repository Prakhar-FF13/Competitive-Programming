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
int visited[1001][1001];
int distanceM[1001][1001];
char traceBack[1001][1001];
//          L, R,  U, D
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs()
{
  int sX, sY;
  queue<pii> q;
  rep(i, 0, n)
  {
    rep(j, 0, m)
    {
      if (arr[i][j] == 'A')
        sX = i, sY = j;
      if (arr[i][j] == 'M')
      {
        q.push(mp(i, j));
        distanceM[i][j] = 0;
        visited[i][j] = 1;
      }

      traceBack[i][j] = '#';
    }
  }

  // multi BFS from monsters.
  while (!q.empty())
  {
    pii z = q.front();
    q.pop();
    int x = z.first;
    int y = z.second;

    rep(i, 0, 4)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n &&
          ny >= 0 && ny < m &&
          arr[nx][ny] != '#' &&
          visited[nx][ny] == 0)
      {
        distanceM[nx][ny] = distanceM[x][y] + 1;
        q.push(mp(nx, ny));
        visited[nx][ny] = 1;
      }
    }
  }

  q.push(mp(sX, sY));
  visited[sX][sY] = 1;
  distanceM[sX][sY] = 0;
  traceBack[sX][sY] = 'S';
  int aX = -1, aY = -1;
  // bfs from person.
  while (!q.empty())
  {
    pii z = q.front();
    q.pop();
    int x = z.first;
    int y = z.second;
    if (x == n - 1 || y == m - 1 || x == 0 || y == 0)
      aX = x, aY = y;
    rep(i, 0, 4)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n &&
          ny >= 0 && ny < m &&
          arr[nx][ny] != '#' &&
          (distanceM[nx][ny] == -1 || distanceM[nx][ny] > distanceM[x][y] + 1))
      {
        distanceM[nx][ny] = distanceM[x][y] + 1;
        q.push(mp(nx, ny));
        if (i == 0)
          traceBack[nx][ny] = 'L';
        else if (i == 1)
          traceBack[nx][ny] = 'R';
        else if (i == 2)
          traceBack[nx][ny] = 'U';
        else
          traceBack[nx][ny] = 'D';
      }
    }
  }

  // Getting the path.
  if (aX == -1)
  {
    cout << "NO";
    return;
  }

  string ans = "";
  while (traceBack[aX][aY] != 'S')
  {
    ans += traceBack[aX][aY];
    if (traceBack[aX][aY] == 'L')
      aY += 1;
    else if (traceBack[aX][aY] == 'R')
      aY -= 1;
    else if (traceBack[aX][aY] == 'U')
      aX += 1;
    else if (traceBack[aX][aY] == 'D')
      aX -= 1;
  }
  reverse(all(ans));
  cout << "YES" << endl;
  cout << ans.size() << endl;
  cout << ans << endl;
}

int main()
{
  cin >> n >> m;
  rep(i, 0, n)
          cin >>
      arr[i];

  ms(visited, 0, sizeof(visited));
  ms(distanceM, -1, sizeof(distanceM));
  bfs();
  return 0;
}