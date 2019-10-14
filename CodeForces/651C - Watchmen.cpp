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

int main(){
    int n;
    cin>>n;
    vll pts(n);
    set<pll> s;
    unordered_map<ll, ll> xC, yC;
    map<pll, ll> dup;
    rep(i, 0, n){
        ll x,y;
        cin>>x>>y;
        pts[i] = mp(x, y);
        s.insert(mp(x, y));
        xC[x]++;
        yC[y]++;
        dup[mp(x, y)]++;
    }
    ll ans = 0;
    for(auto it = xC.begin() ; it != xC.end() ; it++){
        ll x = it->second;
        ans += (x)*(x-1)/2;
    }
    for(auto it = yC.begin() ; it != yC.end() ; it++){
        ll x = it->second;
        ans += (x)*(x-1)/2;
    }
    for(auto it = dup.begin(); it != dup.end() ; it++){
        ll cnt = it->second;
        ans -= ((cnt)*(cnt-1)/2);
    }
    cout<<ans;
    return 0;
}
