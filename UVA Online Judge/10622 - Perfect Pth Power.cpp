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

bitset<1000000> pr;
vi primes;
void sieve(){
    pr[0] = pr[1] = 1;
    rep(i, 2, 1000000)
        if(pr[i] == 0){
            primes.pb(i);
            for(int j = 2*i ; j < 1000000 ; j += i)
                pr[j] = 1;
        }
}

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int getFactors(int x){
    vii f;
    int i = 0;
    while(i < primes.size()){
        int cnt = 0;
        if(x == 1)  break;
        while(x%primes[i] == 0){
            cnt++;
            x/=primes[i];
        }
        if(cnt){
            f.pb({primes[i], cnt});
        }
        i++;
    }
    if(x > 1)   f.pb({x, 1});
    if(f.size() == 1)
        return f[0].second;
    else{
        int g = f[0].second;
        rep(i, 1, f.size())
            g = gcd(g, f[i].second);
        return g;
    }
}

int main(){
    RW()
    sieve();
    int n;
    while(cin>>n){
        if(n == 0)  break;
        int ans = getFactors(abs(n));
        if(n < 0){
            while(ans%2 == 0)
                ans /= 2;
            cout<<ans<<endl;
        }
        else
            cout<<ans<<endl;
    }
    return 0;
}
