#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main(){
    //RW()
    int n;
    cin>>n;
    int arr[n];
    int cnt[5010];
    int dp[5010];
    ms(cnt, 0, sizeof(cnt));
    ms(dp, 0, sizeof(dp));
    rep(i, 0, n){
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    int max_numb = 5005;
    dp[0] = cnt[0];
    rep(i,1,max_numb+1)
        dp[i] = dp[i-1] + cnt[i];
    int ans = 1e9;

    rep(i, 1, max_numb){
        // i is minimum;
        if(cnt[i] == 0) continue;

        int to_remove = dp[i-1]; // all smaller than i.

        // also remove all numbers greater than 2*i;
        int max_i = min(max_numb, (2*i));
        to_remove += dp[max_numb] - dp[max_i];
        ans = min(ans, to_remove);
    }
    cout<<ans;
    return 0;
}
