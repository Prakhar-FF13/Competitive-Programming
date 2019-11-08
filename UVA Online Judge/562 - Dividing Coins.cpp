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
int n;
int sum, maxReqSum;
int dp[110][int(500*110/2)]; // knapsack for sum/2 ans = sum - 2*maxValue; maxValue <= sum/2

void knapSack(vi &arr){
    int cols = maxReqSum+1;
    rep(i ,0, 110)
        dp[i][0] = 0;
    rep(i, 0, cols)
        dp[0][i] = 0;
    rep(i, 1, n+1){
        rep(j, 1, cols){
            if(j - arr[i] >= 0){
                dp[i][j] = max(dp[i-1][j], arr[i] + dp[i-1][j - arr[i]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}


int main(){
    RW()
    tt(){
        cin>>n;
        vi arr(n+1);
        rep(i, 1, n+1)
            cin>>arr[i];
        sum = accumulate(all(arr), 0);
        maxReqSum = sum/2;
        ms(dp, 0, sizeof(dp));
        knapSack(arr);
        cout<<sum - dp[n][maxReqSum]*2<<endl;
    }
    return 0;
}
