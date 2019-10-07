#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
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

int main(){
    string s,t;
    cin>>s>>t;
    if(s.length() > t.length()){
        cout<<0;
        return 0;
    }
    int dpZerosInS[s.length()], dpOnesInS[s.length()];
    ms(dpZerosInS, 0 , sizeof(dpZerosInS));
    ms(dpOnesInS, 0 , sizeof(dpOnesInS));
    rep(i, 0, s.length()){
        if(s[i] == '0') dpZerosInS[i] = 1;
        else            dpOnesInS[i] = 1;
    }
    rep(i,0,s.length()){
        dpZerosInS[i] += (i>0)?dpZerosInS[i-1]:0;
    }
    rep(i,0,s.length()){
        dpOnesInS[i] += (i>0)?dpOnesInS[i-1]:0;
    }

    int dp[t.length()];
    ms(dp, 0, sizeof(dp));
    rep(i, 0, s.length()){
        if(t[i] == '1')
            dp[i] = dpZerosInS[i];
        else
            dp[i] = dpOnesInS[i];
        int sCanMove = t.length() - s.length();
        if(sCanMove >= s.length()) continue;
        int index = i-sCanMove-1;
        if(index < 0)   continue;
        dp[i] -= (t[i] == '1') ? dpZerosInS[index]: dpOnesInS[index];
    }
    int i = s.length();
    while(i < t.length()){
        int sCanMove = min(t.length()-i, s.length());
        if(t[i] == '1')
            dp[i] = dpZerosInS[s.length()-1];
        else
            dp[i] = dpOnesInS[s.length()-1];


        int index = s.length()-sCanMove-1;
        if(index < 0){i++;   continue;}
        dp[i] -= (t[i]=='1')?dpZerosInS[index]:dpOnesInS[index];
        i++;
    }
    ll ans = 0;
    rep(i,0,t.length()){
        ans += dp[i];
    }
    cout<<ans;
    return 0;
}
