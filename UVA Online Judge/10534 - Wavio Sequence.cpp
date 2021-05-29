/*
    Tags - DP LIS
        Very good question.
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

// *****************
// TLE Code.
// Optimized code below this code.
// ******************
int main () {
    RW()
    fsi

    int n;
    while(cin>>n) {
        vi arr(n), rarr(n);
        rep(i, 0, n)    {cin>>arr[i]; rarr[i] = arr[i];}
        reverse(all(rarr));
        vi L(n), L_id, p, R(n), R_id, r;
        L_id.assign(n, 0);
        R_id.assign(n, 0);
        p.assign(n, -1);
        r.assign(n, -1);
        int k = 0, ans = 1;
        unordered_map<int, unordered_map<int, vector<int> > > DS;
        rep(i, 0, n) {
            int position = lower_bound(R.begin(), R.begin() + k, rarr[i]) - R.begin();

            R[position] = rarr[i];
            R_id[position] = i;
            r[i] = position ? R_id[position - 1] : -1;

            if (i > 0)  DS[i] = DS[i-1];
            
            DS[i][position+1].pb(rarr[i]);
            
            if (position == k)  k = position + 1;
        }

        k = 0;

        rep(i, 0, n) {
            int position = lower_bound(L.begin(), L.begin() + k, arr[i]) - L.begin();

            L[position] = arr[i];
            L_id[position] = i;
            p[i] = position ? L_id[position - 1] : -1;

            for(int x = position; x > 0; x--){
                rep(j, 0, DS[n-1-i][x].size()) {
                    if (DS[n-1-i][x][j] < arr[i])
                        ans = max(2*(x) + 1, ans);
                }
            }

            if (position == k) {
                k = position + 1;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}