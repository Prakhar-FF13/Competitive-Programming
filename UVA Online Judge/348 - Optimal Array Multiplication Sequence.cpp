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
vll matrices;
void solve(){
    ll dp[20][20];
    string seq[20][20];
    rep(i, 0, 20)
        rep(j, 0, 20)
            dp[i][j] = 1e9;
    for(int i = 0 ; i < 19; i++){
        dp[i][i] = 0;
        string a = to_string(i+1);
        seq[i][i] = "A" + a;
        if(i < n-1){
            dp[i][i+1] = matrices[i].first * matrices[i].second * matrices[i+1].second;
            string b = to_string(i+2);
            seq[i][i+1] = "(A" + a + " x " + "A" + b + ")";
        }
    }
    for(int k = 2 ; k < n ; k++){
        for(int i = 0; i < n ; i++){
            int l = i+k;
            if(l >= n)  break;
            for(int j = i; j < l ; j++){
                ll cost = dp[i][j] + dp[j+1][l] + (matrices[i].first * matrices[j].second * matrices[l].second);
                string str = "(" + seq[i][j] + " x " + seq[j+1][l] + ")";
                if(cost < dp[i][l]){
                    seq[i][l] = str;
                    dp[i][l] = cost;
                }
            }
        }
    }
    cout<<seq[0][n-1]<<endl;
}
int main(){
    RW()
    int t=1;
    while(cin>>n){
        if(n == 0)
            break;
        matrices.clear();
        rep(i, 0, n){
            int r,c;
            cin>>r>>c;
            matrices.pb({r, c});
        }
        cout<<"Case "<<t++<<": ";
        solve();
    }
    return 0;
}
