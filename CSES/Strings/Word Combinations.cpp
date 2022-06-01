/*
  Tags - Trie + Simple DP.
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
int k;
int trie[int(1e6) + 5][26];
bool isWord[int(1e6) + 5];
int nodeCounter = 1;

void insertInTrie(string x)
{
  int root = 0;
  int i = 0;
  for (i = 0; i < x.length(); i++)
  {
    if (trie[root][x[i] - 'a'] == -1)
      trie[root][x[i] - 'a'] = nodeCounter++;
    root = trie[root][x[i] - 'a'];
  }
  isWord[root] = true;
}

int main()
{
  // RW();
  cin >> str;
  cin >> k;
  rep(i, 0, 1e6 + 1)
  {
    isWord[i] = false;
    rep(j, 0, 26)
        trie[i][j] = -1;
  }
  rep(i, 0, k)
  {
    string x;
    cin >> x;
    insertInTrie(x);
  }
  vi dp(str.length() + 1, 0);
  // base case empty string one way to make, dont take anything.
  dp[str.length()] = 1;
  for (int i = str.length() - 1; i >= 0; i--)
  {
    int j;
    int root = 0;
    for (j = i; j < str.length(); j++)
    {
      if (trie[root][str[j] - 'a'] == -1)
        break;
      root = trie[root][str[j] - 'a'];
      if (isWord[root])
        dp[i] = (dp[i] + dp[j + 1]) % MOD;
    }
  }
  cout << dp[0];
  return 0;
}