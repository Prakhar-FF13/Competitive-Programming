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
int n,m,k,tube=1,cnt=0;

void putValue(int i, int j, int &tube, int &cnt){
  if (tube == k) {
    cout<<i<<" "<<j<<" ";
    return;
  }
  else if (cnt == 2) {
    tube++;
    cout<<endl<<((tube == k) ? n*m - 2*(k-1) : 2)<<" ";
    cnt = 0;
  }
  cnt++;
  cout<<i<<" "<<j<<" ";
}

int main(){
  
  cin>>n>>m>>k;
  
  cout<<((tube == k) ? n*m - 2*(k-1) : 2)<<" ";
  rep(i, 1, n+1) {
    if (i%2)
      rep(j, 1, m+1)
        putValue(i, j, tube, cnt);
    else
      rrep(j, m, 0)
        putValue(i, j, tube, cnt);
  }
  return 0;
}
