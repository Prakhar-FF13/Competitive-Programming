/*
    Tags - Nice Interval Covering Problem - Greedy.
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

int main () {
    RW()
    fsi
    
    int l,g;
    while(cin>>l>>g, !(l == 0 && g == 0)) {
        vii intervals(g);
        rep(i, 0, g) {
            int x, r;   cin>>x>>r;
            intervals[i] = mp(x-r, x+r);
        }

        sort(all(intervals)); // sort by x-coordinate.
    
        int i = 0, coveredR = 0;
        vii gasStations;    // gas stations needed to cover the road.

        while(i < g && coveredR < l) {
            int ind = -1;

            while(i < g && intervals[i].first <= coveredR) {
                if (ind == -1)  ind = i;
                else            ind = intervals[i].second > intervals[ind].second ? i : ind;

                i++;
            }

            if (ind == -1)  break;
            else            gasStations.pb(intervals[ind]), coveredR = intervals[ind].second;
        }

        if (coveredR < l)  cout<<-1<<endl;
        else            cout<<intervals.size() - gasStations.size()<<endl;
    }
    return 0;
}