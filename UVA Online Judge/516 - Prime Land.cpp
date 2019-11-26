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
bitset<1000> pr;
vl primes;

void sieve(){
    pr[0] = pr[1] = 1;
    rep(i, 2, 1000)
        if(pr[i] == 0){
            primes.pb(i);
            for(ll j = 2LL*i ; j < 1000 ; j += i)
                pr[i] = 1;
        }
}

vll getFactors(ll num){
    vll arr;
    int ind = 0;
    while(ind < primes.size()){
        if(num == 1)    break;
        ll cnt=0;
        while(num % primes[ind] == 0){
            num /= primes[ind];
            cnt++;
        }
        if(cnt>0){
            arr.pb({primes[ind], cnt});
        }
        ind++;
    }
    if(num > 1){
        arr.pb({num, 1});
    }
    reverse(all(arr));
    return arr;
}

int main(){
    RW()
    ll n,p;
    sieve();
    while(cin>>n){
        if(n==0)
            break;
        char c;
        scanf(" %d%c", &p, &c);
        ll num = 1 * pow(n, p);
        if(c != '\n')
        while(1){
            scanf("%d %d%c", &n, &p, &c);
            num *= pow(n, p);
            if(c == '\n')   break;
        }
        num-=1;
        vll fact = getFactors(num);
        rep(i, 0, fact.size()){
            cout<<fact[i].first<<" "<<fact[i].second;
            if(i != fact.size() - 1)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
