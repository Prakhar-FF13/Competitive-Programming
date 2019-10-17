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

ll bNeeded, sNeeded, cNeeded;
ll hasB, hasS, hasC;
ll prb,prs,prc;
bool isPossible(ll hams, ll rubs){
    ll bReqPrice = bNeeded > 0 ? ((hams * bNeeded) - hasB) * prb : 0;
    ll sReqPrice = sNeeded > 0 ? ((hams * sNeeded) - hasS) * prs : 0;
    ll cReqPrice = cNeeded > 0 ? ((hams * cNeeded) - hasC) * prc : 0;
    bReqPrice = bReqPrice < 0 ? 0 : bReqPrice;
    sReqPrice = sReqPrice < 0 ? 0 : sReqPrice;
    cReqPrice = cReqPrice < 0 ? 0 : cReqPrice;
    //cout<<bReqPrice<<" "<<sReqPrice<<" "<<cReqPrice<<endl;
    rubs -= bReqPrice + sReqPrice + cReqPrice;
    if(rubs < 0)    return false;
    return true;
}


int main(){
    string str;
    cin>>str;
    bNeeded = 0, sNeeded = 0, cNeeded = 0;
    rep(i, 0 ,str.length())
        if(str[i] == 'B')      bNeeded++;
        else if(str[i] == 'S') sNeeded++;
        else                   cNeeded++;

    cin>>hasB>>hasS>>hasC;
    cin>>prb>>prs>>prc;
    ll rubs;
    cin>>rubs;
    ll low = 1, high = 1e14;
    ll ans = 0;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(isPossible(mid, rubs)){
            low = mid+1;
            ans = mid;
        }else{
            high = mid-1;
        }
    }
    cout<<ans;
    return 0;
}
