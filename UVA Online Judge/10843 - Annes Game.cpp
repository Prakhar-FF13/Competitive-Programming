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

ll compute(ll n, ll mod){
    ll p = n-2;
    ll res=1;
    while(p){
        if(p&1)
            res = (res * n)%mod;
        n = (n * n)%mod;
        p = p>>1;
    }
    return res;
}

int main(){
    RW()
    int Cases;
    cin>>Cases;
    rep(i, 1, Cases+1){
        int n;
        cin>>n;
        cout<<"Case #"<<i<<": ";
        if(n == 1 || n == 2)    cout<<1;
        else                    cout<<compute(n, 2000000011);
        cout<<endl;
    }
    return 0;
}
