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

int main(){
    int n,f;
    cin>>n>>f;
    vector<pair<int, pair<int,int> > > lk;
    rep(i, 0, n){
        int ki, li;
        cin>>ki>>li;
        int x = min(2*ki, li) - min(ki, li);
        lk.pb(mp(x, mp(li, ki)));
    }
    sort(lk.rbegin(), lk.rend());
    ll ans = 0 ;
    rep(i, 0, n){
        pair<int, pair<int,int> > x = lk[i];
        int li = x.second.first, ki = x.second.second;
        if(f > 0) ans += min(li, 2*ki), f--;
        else      ans += min(li, ki);
    }
    cout<<ans;
    return 0;
}
