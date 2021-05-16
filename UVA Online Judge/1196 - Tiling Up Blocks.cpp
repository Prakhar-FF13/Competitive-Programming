/*
    Tags - DP 
        LIS on Pairs
*/

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
#define repit(a)      for(auto it = a.begin(); it != a.end(); it++)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;for(int xt = 1; xt <= t; xt++)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

bool cmp(const pii &x, const pii &y) {
    return (x.first <= y.first && x.second <= y.second);
}

int main () {
  RW()
  fsi

  int n;
  while(cin>>n, n) {
      vii arr(n), L(n); vi L_id, p;
      L_id.assign(n, 0);
      p.assign(n, -1);
      rep(i, 0, n) {
          int l,m;  cin>>l>>m;
          arr[i] = mp(l, m);
          L[i] = mp(0, 0);
      }
      sort(all(arr));
      int k = 0, lis_end = -1;
      rep(i, 0, n) {
          int position = lower_bound(L.begin(), L.begin() + k, arr[i], cmp) - L.begin();

          L[position] = arr[i];
          L_id[position] = i;
          p[i] = position ? L_id[position - 1] : -1;

          if (position == k) {
              k = position + 1;
              lis_end = i;
          }
      }
      cout<<k<<endl;
  }
  cout<<"*"<<endl;

  return 0;
}