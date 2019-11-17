#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
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
typedef vector<ll> vl;
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

const int N = 100*1000 + 9;
char s[N];

int main(){
    RW()
    int n, p;
    scanf("%d %d", &n, &p);
    p--;
    scanf("%s", s);
    if (p >= n / 2)
        p = n - 1 - p;
    int l = 0, r = n / 2 - 1;
    while (l < n / 2 && s[l] == s[n - 1 - l])
        l++;
    while (r >= 0 && s[r] == s[n - 1 - r])
        r--;
    int ans = 0;
    int ch = 0;
    for (int i = l; i <= r; i++) {
        int diff = abs(s[i] - s[n - 1 - i]);
        ch += min(diff, 'z' - 'a' + 1 - diff);
    }
    if (l < r)
        ans += min(abs(p - l), abs(p - r)) + abs(r - l) + ch;
    else if (ch > 0)
        ans += abs(p-l) + ch;
    printf("%d\n", ans);
    return 0;
}
