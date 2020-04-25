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
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

ll gcd(ll a, ll b) {
  if (a == 0)
    return b;
  return gcd(b%a, a);
}

int main(){
  ll a, b, x, y;
  cin>>a>>b>>x>>y;
  ll gc = gcd(x, y);
  x /= gc;
  y /= gc;
  ll lcm = (x * y) / gc;
  ll s = 1, e = 1e9, ans = 0;
  while(s <= e) {
    ll mid = (e - s)/2 + s;
    if (x * mid <= a && y * mid <= b) {
      ans = max(ans, mid);
      s = mid+1;
    }
    if (x * mid > a || y * mid > b) 
      e = mid - 1;
  }
  cout<<x*ans<<" "<<y*ans;
  return 0;
}
