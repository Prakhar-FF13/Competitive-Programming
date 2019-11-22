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
    int n;
    cin>>n;
    vl arr(n);
    rep(i, 0, n)
        cin>>arr[i];
    ll minElem = arr[min_element(all(arr)) - arr.begin()];
    vi indices;
    rep(i, 0, n)
        if(arr[i] == minElem)
            indices.pb(i);

    indices.pb(n + indices[0]); // circling around..
    ll ans = -1;
    rep(i, 1, indices.size()){
        ans = max(ans, indices[i] - indices[i-1] - 1LL); // start at indicies[i-1] + 1.
    }
    cout<<ans + n*minElem;
    return 0;
}
