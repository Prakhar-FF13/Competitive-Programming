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
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main(){
    ll n,A,sum=0;
    cin>>n>>A;
    vector<int> ds(n);
    rep(i, 0, n){
        cin>>ds[i];
        sum += ds[i];
    }
    // instead of calculating what what values di cant take, calculate the range of values which di can take. derive mathematically using s+x=A, n-1<=s<=S-di
    rep(i, 0, n){
        // max value in range which di can take.
        ll upperBoundOfDi = A - (n-1);
        if(upperBoundOfDi > ds[i])
            upperBoundOfDi = ds[i]; // highest we can go to is d[i].

        // minimum value in range which di can take.
        ll lowerBoundOfDi = A - (sum - ds[i]);
        if(lowerBoundOfDi <= 0)
            lowerBoundOfDi = 1; // lowest we can go to is 1.

        int possibleRangeLength = upperBoundOfDi-lowerBoundOfDi+1LL; // length of possible range values allowed.
        int notPossibleRange = ds[i] - possibleRangeLength;
        cout<<notPossibleRange<<" ";
    }
    return 0;
}
