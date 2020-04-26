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
  fsi
  int n,m,v;
  cin>>n>>m>>v;
  if (m < n-1) {
    cout<<-1<<endl;
    return 0;
  }
  if ( m > (n-1) + ((n-2)*(n-3)/2))  {
    cout<<-1;
    return 0;
  }

  rep(i, 1, n+1) {
    if ( m) {
      if (i != v) {
        cout<<v<<" "<<i<<endl;
        m--;
      }
    } else return 0;
  }
  if (m) {
    int start = v == 1 ? 3 : 2;
    rep(i, start, n+1)
      rep(j, i+1, n+1) 
        if (m) {
          if (j != v && i != v) {
            cout<<i<<" "<<j<<endl;
            m--;
          }
        } else return 0;
  }
  return 0;
}
