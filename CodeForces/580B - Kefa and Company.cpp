#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
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
    int n,d;
    cin>>n>>d;
    vll friends;
    rep(i,0,n){
        ll x,f; // money and friendship factor.
        cin>>x>>f;
        friends.pb(mp(x, f));
    }
    sort(friends.begin(), friends.end());
    int i = 0 , j = 1;
    ll currHappiness = friends[i].second;
    ll maxHappiness = currHappiness;
    while( j < friends.size()){
        ll moneyJ = friends[j].first;
        ll moneyI = friends[i].first;
        if(abs(moneyI - moneyJ) >= d){
            maxHappiness = max(maxHappiness, currHappiness);
            currHappiness -= friends[i].second;
            i++;
        }else{
            currHappiness += friends[j].second;
            j++;
        }
    }
    maxHappiness = max(maxHappiness, currHappiness);
    cout<<maxHappiness;
    return 0;
}
