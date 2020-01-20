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

int main(){
    RW()
    ll a,b;
    int t=  1;
    while(cin>>a>>b){
        if(a == 0)  break;
        ll ans = 0;
        ll k1 = max(a, b);
        ll k2 = min(a, b);
        for(ll i = 2; i <= k2 ; i++){
            ll numOfLines = (i-1)*(k1) - (i-1);
            // Sn = n/2*(a + l); l = a + (n-1)*d; a = 0 here; n = l/d + 1;
            ans += (numOfLines + (i-1)) * (numOfLines)/(2*(i-1));
        }
        cout<<"Case "<<t++<<": "<<ans<<endl;
    }
    return 0;
}