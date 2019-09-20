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
    double vp,vd,t,f,c;
    cin>>vp>>vd>>t>>f>>c;
    if(vd <= vp || vp*t >= c)    cout<<0;
    else{
        double princess_dist = vp*t;
        double dragon_chasing_speed = vd - vp;
        int ans = 0;
        while(princess_dist < c){
            double time_to_catch = princess_dist/(dragon_chasing_speed);
            princess_dist += time_to_catch*vp;
            if(princess_dist >= c)  break;
            double dragon_goes_back_time = (princess_dist/vd) + f;
            princess_dist += dragon_goes_back_time*vp;
            ans++;
        }
        cout<<ans;
    }
    return 0;
}
