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

ll n,b,price,quality,ans;
string type,name;
unordered_map<string, vll> partList;

bool possible(ll mid){
    ll cost = 0; // total cost of taken items.
    ll taken = 0; // items taken.
    for(auto it = partList.begin(); it != partList.end() ; it++){ // for each part
        vll parts = it->second;
        ll currPrice = 1e10;
        for(int i = 0; i < parts.size(); i++){ // pick the minium priced part with quality more than mid.
            price = parts[i].first;
            quality = parts[i].second;
            if(quality >= mid){ // quality has to be at-least mid.
                if(price < currPrice){ // quality is >= mid and price is lesser than current chosen item.
                    currPrice = price; // choose this item.
                }
            }
        }
        if(currPrice == 1e10) // could not choose an item.
            return false;
        cost += currPrice; // add cost of part chosen.
        taken++;
    }
    if(taken != partList.size() || cost > b)
        return false;
    return true;
}

void binarySearchTheAnswer(){
    ll low = 0, high = 1e10;
    ans = -1;
    while(low <= high){
        ll mid = low + (high-low)/2;
        if(possible(mid)){
            ans = max(ans, mid);
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
}

int main(){
    RW()
    tt(){
        cin>>n>>b;
        partList.clear();
        rep(i, 0, n){
            cin>>type>>name>>price>>quality;
            partList[type].pb(mp(price, quality));
        }
        binarySearchTheAnswer();
        cout<<ans<<endl;
    }
    return 0;
}
