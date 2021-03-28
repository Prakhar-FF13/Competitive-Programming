/*
    Tags - Very good Problem - Observation, DP, Implementation.
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

    ll fact[14];
    fact[0] = fact[1] = 1;

    rep(i, 2, 14)   fact[i] = i*fact[i-1];

    vector<vector<vl> > dp(14, vector<vl>(14, vl(14)));
    dp[1][1][1] = dp[0][0][0] = 1;

    for(int n = 2; n < 14; n++) {
        for(int p = 1; p <= n; p++) {
            for(int q = 1; q <= p; q++) {
                // left side of largest element needs to have atleast p-1 elems.
                for(int x = p-1 ; x <= n - q; x++) {
                    // no of ways to choose x elems to be put on left side of largest.
                    ll ncx = fact[n-1]/(fact[x]*fact[n-1-x]);

                    // no of ways to arrange left side.
                    ll left = accumulate(dp[x][p-1].begin(), dp[x][p-1].end(), 0);

                    // no of ways to arrange right side.
                    ll right = accumulate(dp[n-1-x][q-1].begin(), dp[n-1-x][q-1].end(), 0);

                    dp[n][p][q] += ncx * left * right;
                }
                dp[n][q][p] = dp[n][p][q];
            }
        }
    }

    tt() {
        int n, p, q;
        cin>>n>>p>>q;
        cout<<dp[n][p][q]<<endl;
    }

    return 0;
}