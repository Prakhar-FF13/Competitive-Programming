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
int n,k;
vl arr;
int dp[10005][10005];
void solve(){
    rep(i,1,n){
        if(arr[i] != arr[i+1]) // length 2 palindrome is not present create it by adding an element.
            dp[i][i+1] = 1;
    }
    //diagonally fill elements.
    for(int k=3; k <=n ; k++){
        for(int i = 1; i<=n ; i++){
            int j = i + k - 1;
            if(j > n)   break;
            if(arr[i] == arr[j])
                dp[i][j] = dp[i+1][j-1];
            else
                dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;

            if(dp[i][j] > k){
                dp[1][n] = 1e9;
                break;
            }
        }
    }
}
int main(){
    RW()
    int x = 1;
    fsi
    tt(){
        cin>>n>>k;
        arr.clear();
        arr.assign(n+3, 0);
        rep(i, 1, n+1)
            cin>>arr[i];
        ms(dp, 0, sizeof(dp));
        if(n > 1)
            solve();
        int ans = dp[1][n];
        cout<<"Case "<<x++<<": ";
        if(ans == 0)
            cout<<"Too easy"<<endl;
        else if(ans > k)
            cout<<"Too difficult"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
