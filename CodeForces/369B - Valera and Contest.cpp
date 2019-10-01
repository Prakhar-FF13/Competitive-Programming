#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main() {
 	int n, k, l, r, s, sk;
 	cin >> n >> k >> l >> r >> s >> sk;
	int tsk = s - sk;
	vector < int > ans(n);
	for(int i = 0; i < k; i++) {
		ans[i] = sk / k;
		if (sk % k != 0) ans[i]++, sk--;
	}
	if (k != n) {
	 	for(int i = k; i < n; i++) {
	 	 	ans[i] = tsk / (n - k);
	 	 	if (tsk % (n - k) != 0) ans[i]++, tsk--;
	 	}
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
    return 0;
}