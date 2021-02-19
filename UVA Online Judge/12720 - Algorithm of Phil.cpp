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

int main () {
    RW()
    fsi
    int c = 1;
    tt() {
        string a;
        ll ans = 0;
        cin>>a;
        int n = a.length();
        int k,l,len = n;
        l = n/2, k = l-1; // very important. do not make i and j equal as it causes wrong answer.
        while(n) {
            int bit;
            if (n&1) {
                if (len-l > k+1)        bit = a[l] - '0', l++;
                else                bit = a[k] - '0', k--;
            } else {
                if (a[k] > a[l])    bit = a[k] - '0', k--;
                else                bit = a[l] - '0', l++;
            }
            ans = (ans << 1) + bit;
            if (ans >= MOD)  ans %= MOD;
            n--;
        }
        cout<<"Case #"<<c++<<": "<<ans<<endl;
    }
}