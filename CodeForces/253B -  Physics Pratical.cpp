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
    rep(i, 0, n)
        cin>>arr[i];
    sort(arr, arr+n);
    rep(i,0,n){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int dp[n];
    rep(i, 0, n){
        // assume arr[i] is minimum;
        int cnt = i;
        int j = lower_bound(arr, arr+n, 2*arr[i])-arr;
        if(j >= n || arr[j] > 2*arr[i]) j--;
        cnt += n-j-1;
        dp[i] = cnt;

        // assume arr[i] is maximum;
        cnt = n-i-1;
        j     = lower_bound(arr, arr+n, arr[i]/2) - arr;
        if( j < 0 || arr[j]*2 < arr[i]) j++;
        cnt += j;
        dp[i] = min(dp[i], cnt);
    }
    int ans = 1e9;
    rep(i, 0, n){
        ans = min(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}
