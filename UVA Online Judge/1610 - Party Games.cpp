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

int cmp(string a, string b) {
    return a < b;
}

int main(){
    RW()
    int n;
    while(cin>>n) {
        if (n == 0) break;
        vector<string> names(n);
        rep(i, 0, n)    cin>>names[i];
        sort(all(names), cmp);
        string mid1 = names[int(n/2)];
        string mid2 = names[int(n/2)-1];
        int bl = mid1.length(), sl = mid2.length();
        int len = min(bl, sl), i;
        string ans = "";
        for(i = 0 ; i < len; i++) {
            char c1 = mid1[i], c2 = mid2[i];
            if (c1 == c2) ans += c2;
            else break;
        }
        for(; i < sl ; i++) {
            char c = mid2[i];
            if (c == 'Z') {
                ans += c;
                continue;
            }   
            ++c;
            if(ans + c == mid1) {
                ans += mid2[i];
            } else {
                if (i != sl-1)  ans += c;
                else            ans += mid2[i]; // if last character then keep same.
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
