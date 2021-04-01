/*
    Tags - very nice two pointer approach great question.
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
    tt() {
        ll p,c;
        cin>>p>>c;
        vector<ll> prod(p);
        vector<ll> cons(c);
        rep(i, 0, p)    cin>>prod[i];
        rep(i, 0, c)    cin>>cons[i];
        if (p == 0) { // no producer make all consumers happy.
            cout<<0<<" "<<0<<endl;
            continue;
        }
        sort(all(prod));    sort(all(cons));
        if (c == 0){ // no consumer, make all producers happy.
            cout<<prod[p-1]<<" "<<0<<endl;
            continue;
        }
        int i = 0, j = 0;
        ll ans = 1e9+7, price;
        while(i < p) {
            while(j < c && cons[j] < prod[i])  j++;
            if (p - 1 - i + j < ans) {
                ans = p - 1 - i + j;
                price = prod[i];
            }
            i++;
        }
        if (ans >= p) { // sell at price 0 if more are angry than producers.
            ans = p;
            price = 0;
        }
        cout<<price<<" "<<ans<<endl;
    }
    return 0;
}