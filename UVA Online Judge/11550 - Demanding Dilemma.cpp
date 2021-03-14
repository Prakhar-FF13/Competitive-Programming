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
    tt() {
        int n,m;
        cin>>n>>m;
        int sumDeg = 0;
        unordered_map<int, vector<int> > mx;
        rep(i, 0, n)
            rep(j, 0, m) {
                int x;
                cin>>x;
                if (x) {
                    sumDeg += x;
                    mx[j].pb(i);
                }
            }

        bool ok = true;
        set<pii> s;
        repit(mx) {
            vector<int> x = it->second;
            if (x.size() != 2)
                ok = false;
            else
                s.insert(make_pair(x[0], x[1]));
        }


        if (sumDeg != 2*m || !ok || s.size() != m)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}