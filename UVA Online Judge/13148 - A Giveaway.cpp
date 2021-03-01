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
    int n;
    unordered_set<int> s;
    s.insert(1), s.insert(64), s.insert(729), s.insert(4096);
    s.insert(15625), s.insert(46656), s.insert(117649), s.insert(262144);
    s.insert(531441), s.insert(1000000), s.insert(1771561), s.insert(2985984);
    s.insert(4826809), s.insert(7529536), s.insert(11390625), s.insert(16777216);
    s.insert(24137569), s.insert(34012224), s.insert(47045881), s.insert(64000000), s.insert(85766121);
    while(cin>>n) {
        if (n == 0) break;
        if (s.find(n) == s.end())   cout<<"Ordinary"<<endl;
        else                        cout<<"Special"<<endl;
    }
    return 0;
}