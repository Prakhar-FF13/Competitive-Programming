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

vl primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(){
    RW()
    ll n;
    while(cin>>n){
        if(n==0)    break;
        if(find(all(primes), n) == primes.end()){
            cout<<"Given number is NOT prime! NO perfect number is available.\n";
            continue;
        }
        ll x = pow(2, n-1);
        ll y = pow(2, n) - 1LL;

        vl divisorsOfX;
        for(ll i = 1; i*i <= x ; i++){
            if(x % i == 0){
                divisorsOfX.pb(i);
                divisorsOfX.pb(x/i);
            }
        }
        vl divisorsOfY;
        for(ll i = 1; i*i <= y ; i++){
            if(y % i == 0){
                divisorsOfY.pb(i);
                divisorsOfY.pb(y/i);
            }
        }
        set<ll> divisors;
        rep(i, 0, divisorsOfX.size()){
            ll divx = divisorsOfX[i];
            rep(j, 0, divisorsOfY.size()){
                ll divy = divisorsOfY[j];
                divisors.insert(divx * divy);
                divisors.insert(divy);
            }
            divisors.insert(divx);
        }
        ll sum = 0;
        for(auto q: divisors){
            if(q != x*y)
                sum += q;
        }
        if(sum == x*y)
            cout<<"Perfect: "<<sum<<"!"<<endl;
        else
            cout<<"Given number is prime. But, NO perfect number is available."<<endl;
    }
    return 0;
}
