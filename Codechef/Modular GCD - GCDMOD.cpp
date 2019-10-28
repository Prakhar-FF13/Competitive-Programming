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
//#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

ll multiplyMOD(ll a, ll b, ll MOD){
    if(a == 0 || b == 0)
        return 0;
    if(a == 1)
        return b;
    if(b == 1)
        return a;
    ll sum = 0;
    while(b){
        if(b&1)
            sum = (sum + a)%MOD;
        a = (a + a)%MOD;
        b = b>>1;
    }
    return sum;
}

ll powerMOD(ll num, ll p, ll MOD){
    if(p == 0)
        return 1;
    ll res = 1;
    while(p){
        if(p & 1)
            res = multiplyMOD(res, num, MOD)%MOD;
        num = multiplyMOD(num, num, MOD)%MOD;
        p = p>>1;
    }
    return res;
}

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
    tt(){
        ll a,b,n;
        cin>>a>>b>>n;
        if(a == b){
            ll x = 1e9+7;
            ll t1 = powerMOD(a, n, x);
            ll t2 = powerMOD(b, n, x);
            cout<<(t1+t2)%x<<endl;
        }else{
            ll x = a - b;
            ll t1 = powerMOD(a, n, x);
            ll t2 = powerMOD(b, n, x);
            t1 = (t1 + t2)%x;
            cout<<gcd(x, t1)<<endl;
        }
    }
    return 0;
}
