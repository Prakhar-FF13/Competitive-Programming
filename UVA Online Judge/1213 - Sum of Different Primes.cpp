/*
  Tags - Very Good 3D Knapsack problem
  DP - very good.
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

vi primes;

void getPrimes(int n)
{
  vi x;
  x.assign(n, 1);
  rep(i, 2, n) if (x[i] == 1) for (int j = 2 * i; j < n; j += i)
      x[j] = 0;
  primes.pb(0);
  rep(i, 2, n) if (x[i] == 1) primes.pb(i);
}

int dp[200][1200][15];

/**
 * idx - index of prime numbers array.
 * Sum - Sum to be found.
 * taken - number of prime numbers allowed to be taken.
*/
int solve(int idx, int Sum, int taken)
{
  // max primes allowed reached but sum still not 0.
  if (Sum > 0 && taken == 0)
    return 0;
  // Sum is 0 and primes allowed is also 0.
  else if (Sum == 0 && taken == 0)
    return 1;
  // sum is < 0 or taken more primes than allowed.
  else if (Sum < 0 || taken < 0)
    return 0;
  // current prime > sum can't include it.
  else if (primes[idx] > Sum)
    return 0;
  // answer already calculated so need to calculate again.
  else if (dp[idx][Sum][taken] != -1)
    return dp[idx][Sum][taken];
  else
  {
    // Do not include the idx prime number.
    int p = solve(idx + 1, Sum, taken);

    dp[idx][Sum][taken] = p;

    // take the idx prime number.
    dp[idx][Sum][taken] += solve(idx + 1, Sum - primes[idx], taken - 1);

    return dp[idx][Sum][taken];
  }
}

int main()
{
  fsi;
  RW();
  int n, k;
  getPrimes(1200);
  ms(dp, -1, sizeof(dp));
  while (cin >> n >> k, n)
  {
    // idx of prime = 1, sum = n, no of primes allowed = 0;
    cout << solve(1, n, k) << endl;
  }

  return 0;
}