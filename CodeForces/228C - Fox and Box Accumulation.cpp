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

int main() {
  int n;
  cin>>n;
  int arr[n], hasTop[n];
  rep(i, 0, n) {
    cin>>arr[i];
    hasTop[i] = 0;
  }
  sort(arr, arr + n);
  int i = 0;
  while( i < n ) {
    for (int j = i+1; j < n ; j++) {
      if (arr[j] == 0)  continue;
      if (arr[j] - hasTop[j] >= 1 + hasTop[i]) {
        hasTop[j] += 1 + hasTop[i];
        hasTop[i] = -1;
        arr[j] = min(arr[j] - hasTop[i] - 1, arr[i]);
        break; 
      }
    }
    i++;
  }
  int cnt = 0;
  rep(i, 0, n) {
    if(hasTop[i] != -1)
      cnt++;
  }
  cout<<cnt;
  return 0;
}
