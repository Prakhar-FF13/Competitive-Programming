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

long double nCr(ll n, ll r) {
    long double ans = 1.0;
    if(r > n-r) r = n-r;
    ll num = 1;
    for(ll i = n ; i > n-r ; i--){
        ans = (ans*i)/num;
        num++;
    }
    return ans;
}
int main(){
    ll m,w,c;
    while(cin>>m>>w>>c){
        if(m == 0 && w == 0)    break;
        long double ans = 0.0;
        long double probm = m*1.0/(m+w);
        for(int i = 0; i <= c ; i+=2){
            ans += nCr(c, i) * pow(probm, i) * pow(1.0-probm, c-i);
        }
        printf("%.7Lf\n", ans);
    }
    return 0;
}
