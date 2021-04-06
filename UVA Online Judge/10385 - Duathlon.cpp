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

double raceStatus(vector<pair<double, double> > &arr, double r, double d) {
    double minTime = 1e9+7;
    int len = arr.size();
    rep(i, 0, len-1) {
        double t1 = r/arr[i].first, t2 = (d-r)/arr[i].second;
        minTime = min(minTime, t1 + t2);
    }
    double t1 = r/arr[len-1].first, t2 = (d-r)/arr[len-1].second;
    double cheaterTime = t1 + t2;

    return (cheaterTime - minTime)*3600.0; // we have to minimize this.
}

int main () {
    RW()
    fsi
    double distance;
    vector<pair<double, double> > speeds;
    while(cin>>distance) {
        speeds.clear();
        int n;
        cin>>n;
        rep(i, 0, n) {
            double x, y;
            cin>>x>>y;
            speeds.pb(mp(x, y));
        }
        double low = 0, high = distance, m1, m2 , ans = 0;
        double eps = 1e-8;
        while(high - low > eps) {
            double delta = (high - low)/3.0;
            m1 = low + delta;
            m2 = high - delta;

            double m1Time = raceStatus(speeds, m1, distance);
            double m2Time = raceStatus(speeds, m2, distance);

            if (m1Time > m2Time)            low = m1;
            else                            high = m2;
        }

        double ansTime = raceStatus(speeds, low, distance);

        if (ansTime > 0 && ansTime > eps)
            cout<<"The cheater cannot win."<<endl;
        else {
            int x = round(-ansTime);
            printf("The cheater can win by %d seconds with r = %.2fkm and k = %.2fkm.\n", x, low, distance - low);
        }
    }
    return 0;
}