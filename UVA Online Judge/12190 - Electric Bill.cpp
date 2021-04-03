/*
    Tags - Very Nice Binary Search the answer problem.
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

ll getCostForUnits(ll units) {
    ll ans = 0;
    if (units > 1000000)    ans += (units - 1000000) * 7,   units = 1000000;
    if (units > 10000)      ans += (units - 10000) * 5,     units = 10000;
    if (units > 100)        ans += (units - 100) * 3,       units = 100;
    if (units > 0)          ans += (units - 0) * 2,         units = 0;

    return ans;
}

/*
    Logic to get units from cost.
    cost is made up of 4 different values
    we subtract each value as the cost passes the range of any value.
    cost = uw * 2 + ux * 3 + uy * 5 + uz * 7; 
*/
ll getUnitsFromCost(ll cost) {
    ll ans = 0;
    // range 0-100 has a max cost of 200.
    if (cost <= 200)                    return cost/2;
    else                                ans += 100, cost -= 200; // remove this range cost.

    // range 101-10000 has a max cost of (10000 - 101 + 1) * 3
    if (cost <= 9900 * 3)               return ans + cost/3;
    else                                ans += 9900, cost -= 9900 * 3;

    // range 10001-1000000 has a max cost of (1000000 - 10001 + 1) * 5
    if (cost <= 990000 * 5)             return ans + cost/5;
    else                                ans += 990000, cost -= 990000 * 5;

    // range 1000000 - infinity.
    return ans + cost/7;
}

int main () {
    RW()
    fsi
    ll A,B;

    while(cin>>A>>B) {
        if (A == 0 || B == 0)   break;
        ll totalWattageConsumed = getUnitsFromCost(A); // this gives x + y.

        ll low = 0, high = totalWattageConsumed;

        while(low <= high) {
            ll unitX = (low + high)/2;
            ll unitY = totalWattageConsumed - unitX;

            ll costX = getCostForUnits(unitX);
            ll costY = getCostForUnits(unitY);

            if (costY - costX == B) {
                cout<<costX<<endl;
                break;
            }

            if (costY - costX > B)  low = unitX + 1;
            else                    high = unitX - 1;
        }
    }
    return 0;
}