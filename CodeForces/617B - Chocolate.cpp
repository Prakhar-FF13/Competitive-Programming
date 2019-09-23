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
int bar[110];
ll dp[110];
ll solve(int index){
    if(index >= n)  return 1;

    if(dp[index] != -1) return dp[index];

    int temp = index;
    ll ans = 0, cnt = 0;
    while(temp < n){
        cnt += bar[temp];
        if(cnt > 1) break;
        if(cnt == 1)
            ans += solve(temp+1);
        temp++;
    }
    return dp[index] = ans;
}

int main(){
    cin>>n;
    rep(i,0,n)
        cin>>bar[i];
    ms(dp, -1, sizeof(dp));
    cout<<solve(0);
    return 0;
}
