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

ll m;
ll dp[100 * 100 * 101];
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    m = 1073741824;
    rep(i, 0, a*b*c + 3)
        dp[i] = 1;
    dp[0] = 0;
    rep(i, 2, (a*b*c)+3){
        for(int j = i ; j < (a*b*c)+3 ; j+=i)
            dp[j]++;
    }
    /*rep(i, 0, a*b*c+1)
        cout<<dp[i]<<" ";
    cout<<endl;*/
    ll ans = 0;
    rep(i, 1, a+1){
        rep(j, 1, b+1){
            rep(k, 1, c+1){
                ans = (ans + dp[i*j*k])%m;
            }
        }
    }
    cout<<ans;
    return 0;
}
