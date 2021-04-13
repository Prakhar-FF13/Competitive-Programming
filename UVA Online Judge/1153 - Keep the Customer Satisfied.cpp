/*
    Tags - Good Sorting + Priority Queue Problem - Must do
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
        int n;  cin>>n;
        vii arr(n);
        rep(i, 0, n) {
            int q, d;   cin>>q>>d;
            arr[i] = mp(d, q);
        }
        sort(all(arr)); // sort by due date.
        priority_queue<int> pq;

        int curTime = 0;
        // general idea - we want to do jobs which take lesser time but also take due date into account.
        // hence sort by due date.
        rep(i, 0, n) {
            pii x = arr[i];
            pq.push(x.second);
            curTime += x.second;

            if (curTime > x.first)
                curTime -= pq.top(), pq.pop();
        }
        cout<<pq.size()<<endl;
        if (xt != t)    cout<<endl;
    }   

    return 0;
}