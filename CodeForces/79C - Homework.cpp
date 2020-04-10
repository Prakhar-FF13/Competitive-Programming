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

int cmp(pair<char, int> a, pair<char, int> b) {
  return a.second < b.second;
}

int main(){
  string str;
  cin>>str;
  int k;
  cin>>k;
  if (k >= str.length()) {
    cout<<0<<endl<<endl;
    return 0;
  }
  pair<char, int> c[26];
  rep(i, 0, 26) {
    c[i] = mp(char(i + 'a'), 0);
  }
  rep(i, 0, str.length()) {
    int ind = str[i] - 'a';
    c[ind].second++;
  }
  sort(c, c + 26, cmp); 
  map<char, int> toDel;
  rep(i, 0, 26)
    if(k > 0 && c[i].second > 0) {
      char q = c[i].first;
      toDel[q] = min(c[i].second, k);
      k -= c[i].second;
    }
  string ans = "";
  set<char> x;
  rep(i, 0, str.length()) {
    if (toDel[str[i]] > 0) {
      toDel[str[i]]--;
    }else {
      ans += str[i];
      x.insert(str[i]);
    }
  }
  cout<<x.size()<<endl;
  cout<<ans<<endl;
  return 0;
}
