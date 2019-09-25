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
map<pii, int> dp;
int solve(int a, int b){
    if(a == b)
        return 0;
    if(dp[mp(a,b)])
        return dp[mp(a,b)];
    int ans = 1e9+5;
    if(a < b){
        if(b%2==0) ans = min(ans, 1+solve(a,b/2));
        if(b%3==0) ans = min(ans, 1+solve(a,b/3));
        if(b%5==0) ans = min(ans, 1+solve(a,b/5));
    }else{
        if(a%2==0) ans = min(ans, 1+solve(a/2,b));
        if(a%3==0) ans = min(ans, 1+solve(a/3,b));
        if(a%5==0) ans = min(ans, 1+solve(a/5,b));
    }
    return dp[mp(a,b)] = ans;
}

int main(){
    int a,b;
    cin>>a>>b;
    int ans = solve(a, b);
    if(ans >= 1e9)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
