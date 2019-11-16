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
int n;
string str[100005];
string revstr[100005];
ll costOfReverse[100005];
ll dp[100005][2];

void solve(){
    dp[0][0] = 0; // dont reverse first string..
    dp[0][1] = costOfReverse[0]; // reverse first string cost.
    rep(i, 1, n){
        string a = str[i-1]; // previous string and current.
        string b = str[i];
        if(a <= b){ // if not reversing any string the cost.
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        }
        a = revstr[i-1];
        if(a <= b){ // reverse previous string and dont reverse current and check.
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
        }
        b = revstr[i];
        if(a <= b){ // both strings reverse.
            dp[i][1] = min(dp[i][1], dp[i-1][1] + costOfReverse[i]);
        }
        a = str[i-1];
        if(a <= b){ // second string reverse.
            dp[i][1] = min(dp[i][1], dp[i-1][0] + costOfReverse[i]);
        }
    }
    ll x = dp[n-1][0];
    ll y = dp[n-1][1];
    ll ans = min(x, y);
    if(ans == 1e17)
        cout<<-1;
    else
        cout<<ans;
    /*cout<<endl<<endl;
    rep(i, 0, n){
        cout<<i<<"  "<<str[i]<<"  "<<dp[i][0]<<"   "<<dp[i][1]<<endl;
    }*/
}

int main(){
    //RW()
    cin>>n;
    for(int i = 0 ; i < n+2 ; i++){
        dp[i][0] = dp[i][1] = 1e17;
    }
    rep(i, 0, n)
        cin>>costOfReverse[i];
    rep(i, 0, n){
        cin>>str[i];
        revstr[i] = str[i];
        reverse(all(revstr[i]));
    }
    solve();
    return 0;
}
