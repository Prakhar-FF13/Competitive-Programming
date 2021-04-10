/*
    Tags - Nice Greedy Problem - Observation + reverse of coin change thinking.
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
        int n;
        cin>>n;

        ll arr[n];
        rep(i, 0, n)    cin>>arr[i];

        ll sum = arr[0], coins = 1; // can always include 1st coin.

        // since we need unique coins, the amount has to be at-least equal to next coin + previous coins taken.
        rep(i, 1, n-1) {
            // if including current coin is > next coin then we would end up getting next coin.
            // so in order for our answer to take this coin we need the sum to be smaller.
            if (sum + arr[i] < arr[i+1])    sum += arr[i], coins++;
        }

        // last coin can always be included (make sure n != 1)
        if (n != 1) coins++;

        cout<<coins<<endl;
    }
    return 0;
}