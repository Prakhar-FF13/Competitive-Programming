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

vl primes; vll prFactors;
bitset<60000> pr;

void sieve(){
    for(ll i = 2; i < 60000; i++)
        if(pr[i] == 0){
            primes.pb(i);
            for(ll j = i*2 ; j < 60000 ; j += i)
                pr[i] = 1;
        }
}

void getPrimeFactors(ll m){
    ll i = 0;
    while(i < primes.size() && primes[i] <= m){
        int cnt = 0;
        while(m % primes[i] == 0){
            m /= primes[i];
            cnt++;
        }
        if(cnt) prFactors.pb({primes[i], cnt});
        i++;
    }
    if(m > 1)
        prFactors.pb({m, 1});
}

ll prOccursInNFact(ll numb, ll n){
    ll ans = 0;
    ll t = numb;
    while(numb <= n){
        ans += n/numb;
        numb *= t;
    }
    return ans;
}

int main(){
    RW()
    ll n,m;
    sieve();
    while(cin>>n>>m){
        if(m == 1 || m == 0 || n >= m){
            cout<<m<<" divides "<<n<<"!"<<endl;
            continue;
        }
        getPrimeFactors(m);
        string ans = "";
        rep(i, 0, prFactors.size()){
            ll reqPow = prFactors[i].second;
            ll numb = prFactors[i].first;
            if(prOccursInNFact(numb, n) < reqPow){
                ans = to_string(m) + " does not divide " + to_string(n) + "!";
                break;
            }
        }
        prFactors.clear();
        if(ans == "")
            cout<<m<<" divides "<<n<<"!"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
