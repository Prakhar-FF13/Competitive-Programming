#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
const int MAXLEN = 2e5 + 100;
int arr[MAXLEN];
int main()
{
  std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int q, a;
	cin >> q;
	while (q--) {
		cin >> a;
		arr[a - 1] += 1;
	}
	int slen = s.length();
	for (int i = 0; i < slen / 2; ++i) {
		if (i != 0) arr[i] += arr[i - 1];
		if (arr[i] & 1) swap(s[i], s[slen - i - 1]);
	}
	cout << s << "\n";
  return 0;
}