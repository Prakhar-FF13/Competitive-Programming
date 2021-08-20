/*
 * Very good DP Knapsack;
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

int N, x, T, K, maxMoney, teaCharge, maxChosen;

typedef struct DimSum
{
  int price;
  double favour;
} DS;

DS ds[110];

double dp[110][1100][25];

double solve(int index, int moneySpent, int chosen)
{
  int totalExpense = moneySpent + ceil(0.1 * (moneySpent + teaCharge)) + teaCharge;
  if (totalExpense > maxMoney || chosen > maxChosen)
    return -10000;
  if (totalExpense == maxMoney || chosen == maxChosen || index == K)
    return 0;

  if (dp[index][moneySpent][chosen] != -1)
    return dp[index][moneySpent][chosen];

  double x = 0, y = 0, z = 0;
  return dp[index][moneySpent][chosen] = max(
             ds[index].favour + solve(index + 1, moneySpent + ds[index].price, chosen + 1),
             max(
                 ds[index].favour * 2 + solve(index + 1, moneySpent + ds[index].price * 2, chosen + 2),
                 solve(index + 1, moneySpent, chosen)));
}

int main()
{
  RW();
  fsi;
  while (cin >> N >> x >> T >> K, N)
  {
    rep(i, 0, 110) rep(j, 0, 1100) rep(k, 0, 25) dp[i][j][k] = -1;
    for (int i = 0; i < K; i++)
    {
      cin >> ds[i].price;
      ds[i].favour = 0;
      for (int j = 0; j <= N; j++)
      {
        double x;
        cin >> x;
        ds[i].favour += x;
      }
    }
    maxMoney = (N + 1) * x;
    teaCharge = (N + 1) * T;
    maxChosen = (N + 1) * 2;
    printf("%.2lf\n", solve(0, 0, 0) / (N + 1));
  }
  return 0;
}