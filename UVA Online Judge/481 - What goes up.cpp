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

void printLis(vi &arr, vi &pi, int i) {
  if (pi[i] == -1)  cout<<arr[i]<<endl;
  else {
    printLis(arr, pi, pi[i]);
    cout<<arr[i]<<endl;
  }
}

int main () {
  RW()
  fsi

  int n;
  vi arr;
  while(cin>>n) arr.pb(n);
  
  n = arr.size();

  vi L_id, L, pi;
  L_id.assign(n, 0); // index of element formaing largest LIS.
  L.assign(n, 0);   // actual LIS elements being stored here.
  pi.assign(n, -1); // parent of LIS elements index.
  int k = 0; // longest LIS found so far has length k.
  int lis_end = -1; // Last element in LIS index.

  rep(i, 0, n) {
    // if arr[i] is to be included then what position in LIS will it occur.
    int position = lower_bound(L.begin(), L.begin() + k, arr[i]) - L.begin();

    L[position] = arr[i]; // put the element.
    L_id[position] = i;   // change the element index in index array.
    // if position is not 0 i.e some other smaller element exist behind it then make that element its parent.
    pi[i] = position ? L_id[position - 1] : -1;  

    if (position == k) {
      k = position + 1;
      lis_end = i;
    }

    if (position == k-1)  lis_end = i;
  }

  cout<<k<<endl<<"-"<<endl;
  printLis(arr, pi, lis_end);

  return 0;
}