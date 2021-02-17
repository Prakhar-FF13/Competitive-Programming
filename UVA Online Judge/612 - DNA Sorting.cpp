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

typedef struct DNA {
    string x;
    int cnt;
} D;

bool cmp (D a, D b)  {
    return a.cnt < b.cnt;
}

int main(){
    RW()
    tt() {
        int n,m;
        cin>>n>>m;
        D arr[m];
        rep(i, 0, m) {
            cin>>arr[i].x;
            arr[i].cnt = 0;
        }
        rep(i, 0, m) {
            string x = arr[i].x;
            int invCount = 0;
            rep(j, 1, n)
                rrep(k, j-1, -1)
                    if (x[k+1] < x[k]) {
                        swap(x[k+1], x[k]);
                        invCount++;
                    } else  break;
            arr[i].cnt = invCount;
        }
        stable_sort(arr, arr+m, cmp);
        rep(i, 0, m)
            cout<<arr[i].x<<endl;

        if (t)
            cout<<endl;
    }
    return 0;
}
