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

bitset<100005> pr;
vi primes;
void sieve(){
    pr[0] = pr[1] = 1;
    rep(i, 2, 100005){
        if(pr[i] == 0){
            primes.pb(i);
            for(ll j = 2LL*i; j < 100005 ; j += i)
                pr[j] = 1;
        }
    }
}

int getFactors(int numb){
    int ind=0, count=0;
    bool div;
    while(ind < primes.size() && numb > 1){
        div = false;
        while(numb%primes[ind] == 0){
            numb /= primes[ind];
            div = true;
        }
        if(div)
            count++;
        ind++;
    }
    if(numb > 1)
        count++;
    return count;
}

int main(){
    RW()
    sieve();
    int numb;
    while(cin>>numb){
        if(numb == 0)
            break;
        int ans = getFactors(numb);
        cout<<numb<<" : "<<ans<<endl;
    }
    return 0;
}
