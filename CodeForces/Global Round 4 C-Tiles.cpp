#include <iostream>

using namespace std;

const int MOD = 998244353;

int main()
{
  int R, C;
  cin >> R >> C;
  int X = 1;
  while (R--)
    X = (2 * X) % MOD;
  while (C--)
    X = (2 * X) % MOD;
  cout << X << endl;
}