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

// Modify the formula from i mod 1 ^ i mod 2.. to -> 1 mod i ^ 2 mod i...

int main(){
    ll n;
    cin>>n;
    ll pXor = 0;
    vector<ll> arr(n);
    rep(i, 0, n){
        cin>>arr[i];
        pXor ^= arr[i]; // calculate p1^p2^p3....p^n
    }
    vector<ll> f(n+3);
    f[0] = 0;
    rep(i, 1, n+3)
        f[i] = f[i-1] ^ i; // calculate 0^1^2^3....^n

    rep(i, 0, n){
        ll term = i+1;
        ll count = n/term;
        if(count & 1)
            pXor ^= f[i]; // xor upto term-1 i.e 0^1^2...^(term-1)
        ll remain = n-term*count;
        pXor ^= f[remain];
    }
    cout<<pXor;
    return 0;
}
