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

bool cmp(pii a, pii b) {
    int x = a.first, y = b.first, modx = a.second, mody = b.second;
    if (modx == mody) {
        if ((x&1) && ((y&1) == 0))    return true;
        else if (((x&1) == 0) && (y&1))   return false;
        else if ((x&1) && (y&1))    return (a > b ? true : false);
        else return (a < b ? true : false);
    }
    else    return (modx < mody ? true : false);
}

int main(){
    RW()
    int n,m;
    while(cin>>n>>m) {
        if (n == 0) {
            cout<<0<<" "<<0<<endl;
            break;
        }
        vector<pii> arr;
        rep(i, 0, n) {
            int x;  cin>>x;
            int xd = (abs(x)%m) * (x >= 0 ? 1 : -1);
            arr.pb(mp(x, xd));
        }
        sort(all(arr), cmp);
        cout<<n<<" "<<m<<endl;
        rep(i, 0, n) {
            cout<<arr[i].first<<endl;
        }
    }
    return 0;
}
