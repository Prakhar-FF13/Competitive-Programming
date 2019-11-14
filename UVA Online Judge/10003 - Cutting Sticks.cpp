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
int l,n;
vi arr(1100);
int dp[1100][1100];
int solve(int low, int high){ // can cut from index i to j with minimum cost.
    if(low == high) // cannot cut this.
        return 0;
    if(low+1 == high) // cannot cut a unit length.
        return 0;
    if(low > high) // low can never be greater than high.
        return 1e9;
    if(dp[low][high] != 1e9) // already calculated the answer fot his.
        return dp[low][high];
    int *ret = &dp[low][high];
    bool canCut = false; // used to check whether [low, high] can be cut further using the indexes provided
    for(int i = low+1 ; i < high ; i++)
        if(arr[i] == 1){
            // cut cost of [low, high] = high-low + cut smaller string from [low, i] + [i, high]
            *ret = min(*ret, high-low + solve(low, i) + solve(i, high));
            canCut = true;
        }
    if(!canCut) *ret = 0; // if shorter string cannot be made using cutting. Make it 0 denoting this cannot be cut further using index to cut at provided.
    return *ret;
}

int main(){
    RW()
    while(cin>>l){
        if(l == 0)  break;
        cin>>n;
        arr.clear();
        arr.assign(l+5, 0);
        rep(i, 0, n){int x; cin>>x; arr[x] = 1;}
        rep(i, 0, 1100)
            rep(j, 0, 1100)
                dp[i][j] = 1e9;
        cout<<"The minimum cutting is "<<solve(0, l)<<"."<<endl;
    }
    return 0;
}
