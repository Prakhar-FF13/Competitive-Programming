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

typedef struct vouchers {
  ll type, l, r, cost, duration;
  vouchers(ll t, ll a, ll b, ll c) {
    type = t, l = a, r = b, cost = c, duration = b - a + 1;
  }
} vouchers;

int cmp (vouchers *a, vouchers *b) {
  ll first = (a->type == 1) ? a->l : a->r;
  ll second = (b->type == 1) ? b->l : b->r;
  if (first != second)
    return first <= second;
  
  first = (a->type == 1) ? a->r : a->l;
  second = (b->type == 1) ? b->r : b->l;
  return first <= second;
}

int main(){
  ll n, x, ans = 1e10;
  cin>>n>>x;
  vector<vouchers*> v;
  rep(i, 0, n) {
    ll l,r,c;
    cin>>l>>r>>c;
    v.pb(new vouchers(1, l, r, c));
    v.pb(new vouchers(2, l, r, c));
  }
  sort(all(v), cmp);
  vector<ll> arr;
  arr.assign(2e5+500, 1e10);
  rep(i, 0, v.size()) {
    ll dur = v[i]->duration;
    // cout<<v[i]->l<<" "<<v[i]->r<<endl;
    if (v[i]->type == 1 && dur < x) {
      ans = min(ans, v[i]->cost + arr[x - dur]);
    }
    if (v[i]->type == 2) {
      arr[dur] = min(arr[dur], v[i]->cost);
    }
  }
  if( ans >= 1e10) {
    cout<<-1;
  }
  else {
    cout<<ans;
  }
  return 0;
}