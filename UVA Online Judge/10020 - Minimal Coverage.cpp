/*
    Tags - Interval Covering Greedy OK Problem.
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
    tt() {
        int m, li, ri;
        cin>>m;

        vii lines;
        while(cin>>li>>ri, !(li == 0 && ri == 0)) {
            if (ri < 0 || li > m)   continue; // lines not contributing to goal.

            lines.pb(mp(li, ri));   
        }

        sort(all(lines));

        int coveredR = 0;
        vii ans;

        int i = 0;
        while(i < lines.size() && coveredR < m) {
            int ind = -1;
            
            // extending our current reach.
            while(  i < lines.size() 
                    && lines[i].first <= coveredR // line has to begin before our current reach.
                ) {
 
                if (ind == -1)  ind = i;
                else            ind = lines[i].second > lines[ind].second ? i : ind;

                i++;
            }

            if (ind != -1) {                  // found the line to extend our reach.
                ans.pb(lines[ind]);
                coveredR = lines[ind].second; // new reach.
            } else {
                i++;
            }
        }
        if (coveredR < m)   cout<<0<<endl;
        else {
            cout<<ans.size()<<endl;
            rep(i, 0 ,ans.size())   cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }

        if (t != xt)  cout<<endl;
    }
    return 0;
}