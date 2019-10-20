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

ll lowBit(ll num){
    ll ans = 1;
    while((num&1) == 0){
        num = num>>1;
        ans *= 2;
    }
    return ans;
}

int main(){
    ll sum, limit;
    cin>>sum>>limit;
    vector<ll> lowBits;
    rep(i, 1, limit+1)
        lowBits.pb(lowBit(i));
    vector<ll> ans;
    for(ll i = lowBits.size()-1 ; i >= 0 ; i--){
        ll low = lowBits[i];
        if(low <= sum){
            sum -= low;
            ans.pb(i+1);
        }
    }
    if(sum > 0)
        cout<<-1;
    else{
        cout<<ans.size()<<endl;
        rep(i, 0 ,ans.size())
            cout<<ans[i]<<" ";
    }
    return 0;
}
