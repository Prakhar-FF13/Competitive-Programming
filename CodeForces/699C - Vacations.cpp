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
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back
int n;
int arr[110];
int dp[110][3];
long long solve(int index, int prev){
    if(index >= n)
        return 0;

    if(dp[index][prev] != -1)
        return dp[index][prev];

    long long ans = 0;

    // resting can be done on any day.
    ans = 1 + solve(index+1, 0);

    // participating in contest can be done, if yesterday not participated.
    if((arr[index] == 1 || arr[index] == 3) && prev !=  1)
        ans = min(ans, solve(index+1, 1));

    // Same conditions for gym.
    if((arr[index] == 2 || arr[index] == 3) && prev != 2)
        ans = min(ans, solve(index+1, 2));

    return dp[index][prev] = ans;
}

int main(){
    cin>>n;
    rep(i,0,n)  cin>>arr[i];
    ms(dp, -1, sizeof(dp));
    cout<<solve(0, 0);
    return 0;
}
