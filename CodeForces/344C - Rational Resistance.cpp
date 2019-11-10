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

// unoptimized.. dry run for 17/3
ll solve(ll a, ll b){
    if(a == b)
        return 1;
    if(a > b)
        return 1 + solve(a-b, b);
    else
        return 1 + solve(a, b-a);
}


// optimized
ll solve2(ll a, ll b){
    if(a == 1)
        return b;
    if(b == 1)
        return a;
    if(a > b)
        return ll(a/b) + solve2(a%b, b);
    else
        return ll(b/a) + solve2(a, b%a);
}
int main(){
    ll a,b;
    cin>>a>>b;
    cout<<solve2(a, b);
    return 0;
}
