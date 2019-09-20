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
int x[100005];
int h[100005];
map<pii, int> dp;
int solve(int index, int prev_blockade, int next_blockade){
    if(index >= n-1)
        return 0;


    if(dp[mp(index, prev_blockade)])
        return dp[mp(index, prev_blockade)];

    int ans = 0;
    // dont cut this damn tree.
    ans = solve(index+1, x[index], x[index+2]);

    // cut this damn tree if possible.
    // cut left if possible.
    if(x[index] - h[index] > prev_blockade)
        ans = max(ans, 1 + solve(index+1, x[index], x[index+2]));
    // cut right if possible.
    if(x[index] + h[index] < next_blockade)
        ans = max(ans, 1 + solve(index+1, x[index] + h[index], x[index+2]));

    return dp[mp(index, prev_blockade)] = ans;
}

int main(){

    cin>>n;
    rep(i, 0, n){
        cin>>x[i]>>h[i];
    }
    if(n == 1)
        cout<<1;
    else if(n == 2)
        cout<<2;
    else{
        cout<<solve(1, x[0], x[2])+2;
    }


    return 0;
}
