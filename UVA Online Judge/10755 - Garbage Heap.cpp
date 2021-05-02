/*
    Tags - 3D DP Prefix Sum.
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
        int n, m, l;
        cin>>n>>m>>l;
        n++, m++, l++; // increment to use 1 based index.
        ll arr[n][m][l];
        rep(i, 1, n)    rep(j, 1, m)    rep(k, 1, l)    cin>>arr[i][j][k];

        rep(i, 1, n)
            rep(j, 1, m)
                rep(k, 1, l) {
                    // 3d prefix sum.
                    arr[i][j][k] += arr[i-1][j][k] + arr[i][j-1][k] + arr[i][j][k-1];
                    arr[i][j][k] -= (arr[i-1][j-1][k] + arr[i-1][j][k-1] + arr[i][j-1][k-1]);
                    arr[i][j][k] += arr[i-1][j-1][k-1];
                }

        ll maxVal = -1e15;

        rep(i, 1, n)    rep(j, 1, m)    rep(k, 1, l)
        rep(ei, i, n)   rep(ej, j, m)   rep(ek, k, l) {
            ll sub = arr[ei][ej][ek];
            sub -= (arr[ei][j-1][ek] + arr[ei][ej][k-1] + arr[i-1][ej][ek]);
            sub += arr[ei][j-1][k-1] + arr[i-1][j-1][ek] + arr[i-1][ej][k-1];
            sub -= arr[i-1][j-1][k-1];

            if (sub > maxVal)   maxVal = sub;
        }

        cout<<maxVal<<endl;
        if (xt != t)    cout<<endl;
    }

    return 0;
}