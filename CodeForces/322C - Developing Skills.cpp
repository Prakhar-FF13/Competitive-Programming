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

int main(){
  int n,k;
  cin>>n>>k;
  pair<int, int> arr[n];
  rep (i, 0, n) {
    int x;
    cin>>x;
    if (x % 10 == 0) {
      arr[i] = {0, x};
      continue;
    }
    int q = int(x/10) + 1;
    int closestToNextMultipleOf10 = q*10 - x;
    arr[i] = {closestToNextMultipleOf10, x};
  }
  sort(arr, arr + n);
  int ans = 0, extraScore = 0;
  rep(i, 0, n) {
    pii x = arr[i];
    if ( k >= x.first) {
      k -= x.first;
      ans += (x.second + x.first)/10;
      extraScore += max(0, (100 - x.second - x.first)/10);
    } else {
      ans += x.second/10;
    }
  }
  while (k >= 10 && extraScore > 0) {
    k -= 10;
    ans++;
    extraScore--;
  }
  cout<<ans;
  return 0;
}
