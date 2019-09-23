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
    int xa,xb,ya,yb;
    cin>>xa>>ya>>xb>>yb;
    int n;
    cin>>n;
    set<pair<pii, int> > heaters;
    rep(i,0,n){
        int x,y,r;
        cin>>x>>y>>r;
        heaters.insert(mp(mp(x,y), r));
    }
    int x1 = min(xa, xb);
    int x2 = max(xa, xb);
    int y1 = min(ya, yb);
    int y2 = max(ya, yb);

    ll ans = 0;
    rep(i, x1, x2+1){
        bool blanked_needed_ya = true;
        bool blanked_needed_yb = true;
        for(auto it=heaters.begin();it!=heaters.end();it++){
            if(!blanked_needed_ya && !blanked_needed_yb) break;
            pair<pii, int> pos_h = *it;
            int xh = pos_h.first.first;
            int yh = pos_h.first.second;
            int rad = pos_h.second;

            double distance1 = sqrt(pow(i-xh, 2) + pow(y1-yh, 2));
            double distance2 = sqrt(pow(i-xh, 2) + pow(y2-yh, 2));

            if(distance1 <= rad)    blanked_needed_ya = false;
            if(distance2 <= rad)    blanked_needed_yb = false;

        }
        if(blanked_needed_ya)
            ans++;
        if(blanked_needed_yb)
            ans++;
    }
    y1++; y2--;
    rep(i, y1, y2+1){
        bool blanked_needed_xa = true;
        bool blanked_needed_xb = true;
        for(auto it=heaters.begin();it!=heaters.end();it++){
            if(!blanked_needed_xa && !blanked_needed_xb) break;
            pair<pii, int> pos_h = *it;
            int xh = pos_h.first.first;
            int yh = pos_h.first.second;
            int rad = pos_h.second;

            double distance1 = sqrt(pow(i-yh, 2) + pow(x1-xh, 2));
            double distance2 = sqrt(pow(i-yh, 2) + pow(x2-xh, 2));

            if(distance1 <= rad)    blanked_needed_xa = false;
            if(distance2 <= rad)    blanked_needed_xb = false;

        }
        if(blanked_needed_xa)
            ans++;
        if(blanked_needed_xb)
            ans++;
    }
    cout<<ans;
    return 0;
}
