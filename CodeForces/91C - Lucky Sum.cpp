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

ll lucky;

ll digits(int num) {
  ll cnt = 0;
  while(num) {
    cnt++;
    num /= 10;
  }
  return cnt;
}

void initializeLucky(ll num) {
  lucky = 0;
  ll dgt = digits(num);
  rep(i, 0, dgt){
    lucky *= 10;
    lucky += 4;
  }
}

void nextLucky() {
  string str = "";
  ll num = lucky;
  while(num) {
    str += to_string(num%10);
    num /= 10;
  }
  int i = 0;
  while(i < str.length()) {
    if (str[i] == '4') {
      str[i] = '7';
      break;
    }else {
      str[i] = '4';
    }
    i++;
  }
  if (i == str.length())
    str += '4';

  lucky = 0;
  rrep(i, str.length()-1, -1) {
    lucky *= 10;
    lucky += int(str[i] - '0');
  }
}

int main(){
  ll l, r;
  cin>>l>>r;
  initializeLucky(l);
  ll sum = 0;
  while (l <= r) {
    while (lucky < l) nextLucky();
    ll diff = min(r, lucky) - l + 1;
    sum += diff * lucky;
    l += diff;
    // cout<<lucky<<" "<<diff<<endl;
  }
  cout<<sum<<endl;
  return 0;
}
