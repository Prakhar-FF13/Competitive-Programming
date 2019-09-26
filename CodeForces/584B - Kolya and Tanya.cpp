#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
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
ll powMod(ll num, ll p){
    ll res = 1;
    while(p>0){
        if(p&1)
            res = (res%MOD * num%MOD)%MOD;
        num = (num%MOD * num%MOD)%MOD;
        p=p>>1;
    }
    return res;
}
int main(){
    ll n;
    cin>>n;
    cout<<(powMod(27, n) - powMod(7, n) + MOD)%MOD;
    return 0;
}
