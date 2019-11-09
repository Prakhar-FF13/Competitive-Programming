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
int n,k;
vi arr;
int dp[10010][110]; // knapsack like DP using upto ith element how many remainders can i get from 0 to k-1

void solve(){
    int rem = arr[0]%k;
    int sign = rem>=0?1:-1;
    dp[0][rem*sign] = 1*sign;
    rep(i, 1, n){
        rep(j, 0, k){
            if(dp[i-1][j] != 0){ //dp[i-1][j] != 0 means using upto i-1 elements we can generate a remainder of j, add/subtract current element i.e ith element remainder to get remainders which can be generated upto i. if after using all n elements if [n-1][0] is still 0 which would then mean that we have cannot have a sequence which generate a remainder of 0.
                int remUtpIMinus1 = j*dp[i-1][j];
                rem = (arr[i]%k + remUtpIMinus1)%k;
                sign = rem>=0?1:-1;
                dp[i][rem*sign] = 1*sign;
                rem = ((-arr[i])%k + remUtpIMinus1)%k;
                sign = rem>=0?1:-1;
                dp[i][rem*sign] = 1*sign;
            }
        }
    }
}
int main(){
    RW()
    tt(){
        cin>>n>>k;
        arr.clear();
        rep(i, 0, n){
            int x;
            cin>>x;
            arr.pb(x);
        }
        ms(dp, 0, sizeof(dp));
        solve();
        if(dp[n-1][0] != 0)
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;

    }
    return 0;
}
