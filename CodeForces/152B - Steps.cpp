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

bool isPossible(ll n, ll m, ll x, ll y, ll dx, ll dy, ll mid){
    ll nx = x + mid*dx;
    ll ny = y + mid*dy;
    if(nx < 1 || nx > n)  return false;
    if(ny < 1 || ny > m)  return false;
    return true;
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll xc,yc;
    cin>>xc>>yc;
    ll k;
    cin>>k;
    long long ans = 0;
    while(k--){
        ll dx,dy;
        cin>>dx>>dy;
        ll newX = xc;
        ll newY = yc;
        ll low=1,high=1000000001;
        ll cnt=0;
        while(low <= high){
            ll mid = high - (high-low)/2;
            if(isPossible(n, m, newX, newY, dx, dy, mid)){
                low = mid+1;
                cnt = mid;
            }
            else
                high = mid-1;
        }
        newX = xc + cnt*dx;
        newY = yc + cnt*dy;
        if(newX == xc && newY == yc)
            continue;
        ans += cnt;
        xc = newX;
        yc = newY;

    }
    cout<<ans;
    return 0;
}
