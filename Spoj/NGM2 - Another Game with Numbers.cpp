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
ll n,k;
vector<ll> numbs;
ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}
ll cutNumbers = 0;
void getNumbers(int index, vector<ll> &curr){
    if(index == numbs.size()){
        if(curr.size() == 0)    return;
        ll res = curr[0];
        rep(i, 1, curr.size()){
            res = lcm(res, curr[i]);
        }
        ll numByRes = n/res;
        if(curr.size() & 1) cutNumbers += numByRes;
        else                cutNumbers -= numByRes;

        return;
    }
    getNumbers(index+1, curr);
    curr.pb(numbs[index]);
    getNumbers(index+1, curr);
    curr.pob();
}
int main(){
    cin>>n>>k;
    rep(i, 0, k){
        ll x;
        cin>>x;
        numbs.pb(x);
    }
    vector<ll> x;
    getNumbers(0, x);
    cout<<n-cutNumbers;
    return 0;
}
