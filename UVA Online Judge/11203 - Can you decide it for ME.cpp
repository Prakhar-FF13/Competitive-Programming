#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
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

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

int main(){
	RW()
    fsi
	int T;
	cin >> T;
	while (T--) {
		string S;
		cin >> S;
		int Q = 0, M = 0, E = 0;
		int L = S.length();
		int i, j;
		FOI(i, 0, L-1) {
			if (S[i] == '?') ++Q;
			if (S[i] == 'M') ++M;
			if (S[i] == 'E') ++E;
		}
		if (Q + M + E != L || M != 1 || E != 1 || Q < 4) {
			cout << "no-theorem\n";
			continue;
		}
		int q1 = 0, q2 = 0, q3 = 0;
		int iM = (int) S.find("M");
		int iE = (int) S.find("E");
		if (!(iM > 0 && iE > iM + 1 && iE < L - 2)) {
			cout << "no-theorem\n";
			continue;
		}
		FOI(i, 0, iM-1)
			if (S[i] == '?') ++q1;
		FOI(i, iM+1, iE-1)
			if (S[i] == '?') ++q2;
		FOI(i, iE+1, L-1)
			if (S[i] == '?') ++q3;
			
		if (q1 > 0 && q2 > 0 && q3 > 1 && q2 == q3 - q1)
			cout << "theorem\n";
		else
			cout << "no-theorem\n";
	}
	return 0;
}