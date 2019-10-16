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
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back
ll arr[20];
ll ans;

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/(gcd(a, b));
}

void numbDivByMs(ll n, ll m, ll index, vector<ll> &x){
    if(index == m){
        if(x.size() == 0)   return;
        ll sign = ((x.size()&1) == 1) ? 1:-1;
        ll res = x[0];
        rep(i ,1, x.size()){
            res = lcm(res, x[i]);
        }
        ans += sign * (n/res);
        return;
    }
    x.push_back(arr[index]);
    numbDivByMs(n, m, index+1, x);
    x.pop_back();
    numbDivByMs(n, m, index+1, x);
}

int main(){
    ll n, m;
    RW()
    while(cin>>n>>m){
        ans = 0;
        rep(i, 0, m){
            cin>>arr[i];
        }
        vector<ll> x;
        numbDivByMs(n, m, 0, x);
        cout<<n-ans<<endl;
    }
    return 0;
}
